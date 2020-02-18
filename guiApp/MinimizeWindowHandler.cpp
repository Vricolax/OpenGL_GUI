#include "MinimizeWindowHandler.h"
#include "WindowManager.h"
#include <iostream>

MinimizeWindowHandler::MinimizeWindowHandler(Window *window)
{
	this->window = window;

	// store original size of window
	original_size = Vector2D(window->GetSize());
}

MinimizeWindowHandler::~MinimizeWindowHandler(void)
{
}

void MinimizeWindowHandler::OnMouseOver(int x, int y)
{
}

void MinimizeWindowHandler::OnMouseAway(int x, int y)
{
}

void MinimizeWindowHandler::OnMousePress(int x, int y)
{
}

void MinimizeWindowHandler::OnMouseRelease(int x, int y)
{
}

void MinimizeWindowHandler::OnMouseClick(int x, int y)
{
	// hide all guiitems of the window
	std::vector<GUIItem*> items = window->GetChildItems();
	for (unsigned int i = 3; i < items.size(); i ++)
	{
		items[i]->hide();
	}

	// set size of window to minimum
	window->SetSize(original_size.GetX(), 35.0f);
}
