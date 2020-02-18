#pragma once
#include "EventHandler.h"
#include "Window.h"
#include "Vector2D.h"

class MinimizeWindowHandler : public EventHandler
{
private:
	//original size of the window
	Vector2D original_size;
	// window for the handler
	Window *window;
public:
	MinimizeWindowHandler(Window *window);
	~MinimizeWindowHandler(void);

	//Mouse handlers
	void OnMouseOver(int x, int y);
	void OnMouseAway(int x, int y);
	void OnMousePress(int x, int y);
	void OnMouseRelease(int x, int y);
	void OnMouseClick(int x, int y);
};

