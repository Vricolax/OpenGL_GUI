#pragma once
#include "EventHandler.h"
#include "Window.h"
#include "Vector2D.h"

class MaximizeWindowHandler : public EventHandler
{
private:
	//Store the original size of the window
	Vector2D original_size;
	Window *window;
public:
	MaximizeWindowHandler(Window *window);
	~MaximizeWindowHandler(void);

	//Mouse handlers
	void OnMouseOver(int x, int y);
	void OnMouseAway(int x, int y);
	void OnMousePress(int x, int y);
	void OnMouseRelease(int x, int y);
	void OnMouseClick(int x, int y);
};

