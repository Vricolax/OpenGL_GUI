#pragma once
#include "EventHandler.h"
#include "Window.h"
#include "Color.h"

class ChangeWindowColorHandler : public EventHandler
{
private:
	//Handle actions for windows
	Window * window;
	//Color arguments: r = red, g = green, b = blue
	float r,g,b;
	//Store the original color of an object
	Color originalColor;
public:
	ChangeWindowColorHandler(Window* window);
	~ChangeWindowColorHandler();

	//Mouse handlers
	void OnMouseOver(int x, int y);
	void OnMouseAway(int x, int y);
	void OnMousePress(int x, int y);
	void OnMouseRelease(int x, int y);
	void OnMouseClick(int x, int y);
};

