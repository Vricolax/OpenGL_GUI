#pragma once
#include "EventHandler.h"
#include "Window.h"

class ExitWindowHandler : public EventHandler
{
private:
	Window *window;
public:
	ExitWindowHandler(Window *window);
	~ExitWindowHandler(void);

	//Mouse handlers
	void OnMouseOver(int x, int y);
	void OnMouseAway(int x, int y);
	void OnMousePress(int x, int y);
	void OnMouseRelease(int x, int y);
	void OnMouseClick(int x, int y);
};

