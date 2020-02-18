#include "MaximizeWindowHandler.h"


MaximizeWindowHandler::MaximizeWindowHandler(Window *window)
{
	this->window = window;
	
	// get original size of the window
	original_size = Vector2D(window->GetSize());
}


MaximizeWindowHandler::~MaximizeWindowHandler(void)
{
}
void MaximizeWindowHandler::OnMouseOver(int x, int y)
{
}

void MaximizeWindowHandler::OnMouseAway(int x, int y)
{
}

void MaximizeWindowHandler::OnMousePress(int x, int y)
{
}

void MaximizeWindowHandler::OnMouseRelease(int x, int y)
{
}

void MaximizeWindowHandler::OnMouseClick(int x, int y)
{
	// show all guiitems of the window
	std::vector<GUIItem*> items = window->GetChildItems();
	for (unsigned int i = 3; i < items.size(); i ++)
	{
		items[i]->show();
	}
	
	// restore window's size
	window->SetSize(original_size.GetX(), original_size.GetY());
}
