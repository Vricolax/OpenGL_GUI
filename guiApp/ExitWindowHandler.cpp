#include "ExitWindowHandler.h"
#include <iostream>

ExitWindowHandler::ExitWindowHandler(Window *window)
{
	// set the handler's window
	this->window = window;
}


ExitWindowHandler::~ExitWindowHandler(void)
{
}

void ExitWindowHandler::OnMouseOver(int x, int y)
{
}

void ExitWindowHandler::OnMouseAway(int x, int y)
{
}

void ExitWindowHandler::OnMousePress(int x, int y)
{
}

void ExitWindowHandler::OnMouseRelease(int x, int y)
{
}

void ExitWindowHandler::OnMouseClick(int x, int y)
{
	// give an order to the window to close
	window->Close();
}
