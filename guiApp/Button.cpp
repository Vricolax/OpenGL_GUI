#include "Button.h"
#include "Renderer.h"
#include <iostream>

using namespace std;

// default button
Button::Button(void)
{
	label = Label("");
	SetPosition(0, 0);
	SetSize(30, 60);
	handler = NULL;
}

// Creates a Button object with a label text in (x,y) position.
Button::Button(Label &label, float x, float y)
{
	// copy the label
	this->label = Label(label);

	// set position
	SetPosition(x, y);

	// set size a little bigger that the label
	m_size.SetX(label.GetSize().GetX() + 1);
	m_size.SetY(label.GetSize().GetY() + 1);

	// event handler is NULL for now
	handler = NULL;
}

// Duplicate constructor
Button::Button(const Button &button)
{
	label = Label(button.label);
	m_position = Vector2D(button.m_position);
	m_offset = Vector2D(button.m_offset);
	m_size = Vector2D(button.m_size);
	color = Color(button.color);
	if (button.m_renderer)
		SetRenderer(button.m_renderer);
	this->handler = NULL;
}

// MouseMove Event Generation
bool Button::MouseMove ( int x, int y )
{
	// check if mouse is hovering over button
	bool selected = isSelected(x, y);

	// if it is hovering and mouse is not pressed
	// change the button's color to "highlighted"
	// if the event handler is not null, call OnMouseOver
	if (!mousePressed && selected)
	{
		color.SetColor(0.65f, 0.65f ,0.75f);
		if (handler != NULL)
			handler->OnMouseOver(x,y);

		// mouse is simply hovering over button
		return selected;
	}
	
	// if mouse is away and not pressed
	// change the button's color to "mouse away"
	// calls the OnMouseAway of the event handler
	else if (!mousePressed && !selected)
	{
		color.SetColor(0.6f, 0.6f ,0.7f);
		if (handler != NULL)
			handler->OnMouseAway(x,y);

		// mouse is not hovering or pressing on the button
		return false;
	}

	// if button is pressed and selected execute OnMouseOver
	// if button is pressed and not selected execute OnMouseAway
	else
	{
		if (handler != NULL)
			if (selected)
				handler->OnMouseOver(x,y);
			else
				handler->OnMouseAway(x, y);
		return selected;
	}
}
bool Button::MouseLBDown ( int x, int y )
{
	// if button is selected, change color to "button pressed"
	// and call the OnMousePress of the event handler
	if (isSelected(x, y))
	{
		color.SetColor(0.5f, 0.5f ,0.6f);

		// keeps track of the mouse presses for click validation
		down = 1;
		if(handler != NULL)
			handler->OnMousePress(x,y);

		mousePressed = true;
		return true;
	}

	// reset mousePressed
	else
	{
		// keeps track of the mouse presses for click validation
		down = 0;
		mousePressed = false;
		return false;
	}
}

void Button::SetEventHandler(EventHandler *handler)
{
	this->handler = handler;
}

bool Button::MouseLBUp ( int x, int y )
{
	// if button is selected and was previously pressed
	// do click
	if (isSelected(x, y) && down == 1)
	{
		color.SetColor(0.6f, 0.6f, 0.7f);

		// keeps track of the mouse presses for click validation
		down = 0;
		if (handler != NULL)
		{
			handler->OnMouseRelease(x, y);
			handler->OnMouseClick(x, y);
		}
		mousePressed = false;
		return true;

		// or do nothing
	} else {
		// keeps track of the mouse presses for click validation
		down = 1;

		if (handler != NULL)
			handler->OnMouseRelease(x,y);
		mousePressed = false;
		return false;
	}
}

void Button::SetRenderer(Renderer *renderer)
{
	m_renderer = renderer;
	m_renderer->IncreaseCounter();
	
	// safely set a renderer to the label
	if (!label.hasRenderer())
		label.SetRenderer(renderer);
}

Button::~Button(void)
{
}

void Button::draw()
{
	// draw button
	if (m_renderer)
		m_renderer->draw(this);
}

Vector2D Button::GetSize(void)
{
	// get size
	return Vector2D(m_size);
}

Label Button::GetLabel()
{
	// safely get button's text
	return Label(label);
}