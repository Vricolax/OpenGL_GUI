#include "Menu.h"
#include "Renderer.h"
#include <iostream>

// Creates a Menu with a Title position and size
Menu::Menu(Label &title, float x, float y, float width, float height)
{
	SetPosition(x, y);
	this->title = Label(title);
	this->title.SetPosition(10.0f, 10.0f);
	m_size.SetX(width);
	m_size.SetY(height);
	is_folded = true;
}


Menu::~Menu(void)
{
}

void Menu::AddSelection(Selection *selection)
{
	// set renderer to the new selection
	if (!selection->hasRenderer())
	{
		selection->SetRenderer(m_renderer);
	}

	// add selection to vector
	m_selections.push_back(selection);

	// change the width of the menu if the new selection is wider
	if (selection->GetSize().GetX() > selection_width)
	{
		selection_width = selection->GetSize().GetX();
	}

	// reset the all the selections' widths
	for (unsigned int i = 0; i < m_selections.size(); i ++)
	{
		m_selections[i]->SetSize(selection_width, m_size.GetY());
	}
}

void Menu::SetSelectionWidth(float width)
{
	// reset all selections' width to the new one manually
	for (unsigned int i = 0; i < m_selections.size(); i ++)
	{
		m_selections[i]->SetSize(width, GetSize().GetY());
	}
}

float Menu::GetSelectionWidth()
{
	return selection_width;
}

std::vector<Selection*> Menu::GetSelections(void)
{
	// get selections
	return std::vector<Selection*>(m_selections);
}

bool Menu::MouseMove ( int x, int y )
{
	// equivalent to button's and selection's event handling

	bool selected = isSelected(x, y);
	// if simple hovering
	if (!mousePressed && selected)
	{
		if (isFolded())
		{
			color.SetColor(0.65f, 0.65f, 0.75f);
		}
		else
		{
			color.SetColor(0.85f, 0.85f ,0.85f);
		}
	}
	// if not hovering
	else if (!mousePressed && !selected)
	{
		if (isFolded())
		{
			color.SetColor(0.6f, 0.6f, 0.7f);
		}
		else
		{
			color.SetColor(0.75f, 0.75f ,0.85f);
		}
	}

	// run event handlers of selections for MouseLBDown
	if (!isFolded())
	{
		for (unsigned int i = 0; i < m_selections.size(); i ++)
		{
			m_selections[i]->MouseMove(x, y);
		}
	}
	return isSelected(x, y);
}

bool Menu::MouseLBDown ( int x, int y )
{
	// equivalent to button's and selection's event handling

	if (isSelected(x, y))
	{
		if (is_folded)
		{
			color.SetColor(0.75f, 0.75f ,0.85f);
		}
		else
		{
			color.SetColor(0.65f, 0.65f ,0.75f);
		}
		down = 1;
		mousePressed = true;
//		mouseClicked = false;
	}
	else
	{
		down = 0;
		mousePressed = false;
//		mouseClicked = false;
	}

	if (mousePressed)
	{
		is_folded = !is_folded;
	}


	for (unsigned int i = 0; i < m_selections.size(); i ++)
	{
		m_selections[i]->MouseLBDown(x, y);
	}

	// run event handlers of selections for MouseLBDown


	if (!isFolded())
	{
		for (unsigned int i = 0; i < m_selections.size(); i ++)
		{
			m_selections[i]->MouseLBDown(x, y);
		}
	}
	return isSelected(x, y);
}

bool Menu::MouseLBUp ( int x, int y )
{
	// equivalent to button's and selection's event handling

	if (isSelected(x, y) && down == 1)
	{
		color.SetColor(0.6f, 0.6f, 0.7f);
		down = 0;
		mousePressed = false;
//		mouseClicked = true;
	} else {
		down = 1;
//		mouseClicked = false;
		mousePressed = false;
	}

	// run event handlers of selections for MouseLBDown
	if (!isFolded())
	{
		for (unsigned int i = 0; i < m_selections.size(); i ++)
		{
			m_selections[i]->MouseLBUp(x, y);
		}
	}

	if (!isSelected(x, y))
	{
		is_folded = true;
	}
	return isSelected(x, y);
}

bool Menu::isFolded()
{
	return is_folded;
}

void Menu::SetRenderer(Renderer *renderer)
{
	m_renderer = renderer;
	m_renderer->IncreaseCounter();

	// set title's renderer
	if (!title.hasRenderer())
		title.SetRenderer(m_renderer);

	// set the selections' renderer
	for (unsigned int i = 0; i < m_selections.size(); i ++)
	{
		if (!m_selections[i]->hasRenderer())
		{
			m_selections[i]->SetRenderer(renderer);
		}
	}
}

Label Menu::GetTitle()
{
	// safely get title
	return Label(title);
}

void Menu::draw()
{
	// draw menu
	if (m_renderer != NULL)
		m_renderer->draw(this);
}

bool Menu::isPressed()
{
	// if any selection is pressed, then the whole menu is pressed
	bool any_item_pressed = mousePressed;
	for (unsigned int i = 0; i < m_selections.size(); i ++)
	{
		if (m_selections[i]->isPressed())
		{
			any_item_pressed = true;
		}
	}
	return any_item_pressed;
}
