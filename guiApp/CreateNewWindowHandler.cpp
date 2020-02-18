#include "CreateNewWindowHandler.h"
#include "Window.h"
#include "Button.h"
#include "Label.h"
#include "ChangeWindowColorHandler.h"
#include <iostream>

CreateNewWindowHandler::CreateNewWindowHandler(WindowManager *window_mgr)
{
	this->window_mgr = window_mgr;
}

CreateNewWindowHandler::~CreateNewWindowHandler(void)
{
}

void CreateNewWindowHandler::OnMouseOver(int x, int y)
{
}

void CreateNewWindowHandler::OnMouseAway(int x, int y)
{
}

void CreateNewWindowHandler::OnMousePress(int x, int y)
{
}

void CreateNewWindowHandler::OnMouseRelease(int x, int y)
{
}

void CreateNewWindowHandler::OnMouseClick(int x, int y)
{
	// creates new window at approximately the center of the OpenGL window
	Window *win = new Window(300, 300, 400, 400);

	// setting up the new window
	win->SetColor(0.8f, 0.6f, 0.4f);
	win->SetTitle(new Label("New Window"));

	// Create a new "Change Color" label for a button
	Label label = Label("Change Color");
	label.SetPosition(15.0f,10.0f);

	// Create a new change color Button
	Button *button = new Button(label,100,150);
	ChangeWindowColorHandler *changeColor_handler = new ChangeWindowColorHandler(win);
	button->SetEventHandler(changeColor_handler);

	// adds a new change color button to the window
	win->AddChild(button);
	window_mgr->AddWindow(win);
}
