#include "ChangeWindowColorHandler.h"
#include <iostream>

ChangeWindowColorHandler::ChangeWindowColorHandler(Window* window)
{
	this->window = window;
	
	//Store the original color of the window
	this->originalColor = window->GetColor();
}


ChangeWindowColorHandler::~ChangeWindowColorHandler()
{
}

void ChangeWindowColorHandler::OnMouseOver(int x, int y)
{
}

void ChangeWindowColorHandler::OnMouseAway(int x, int y)
{
}

void ChangeWindowColorHandler::OnMousePress(int x, int y)
{
}

void ChangeWindowColorHandler::OnMouseRelease(int x, int y)
{
}

void ChangeWindowColorHandler::OnMouseClick(int x, int y)
{
	// randomly generate new color (r, g, b)
	r= ((float) rand()) / (float) RAND_MAX;
	g= ((float) rand()) / (float) RAND_MAX;
	b= ((float) rand()) / (float) RAND_MAX;

	// set color to the window
	window->SetColor(r,g,b);
}
