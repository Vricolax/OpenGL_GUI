#pragma once
#include "EventHandler.h"
#include "WindowManager.h"

class CreateNewWindowHandler : public EventHandler
{
private:
	//Handle WindowManager actions
	WindowManager *window_mgr;
public:
	CreateNewWindowHandler(WindowManager *window_mgr);
	~CreateNewWindowHandler(void);

	//Mouse handlers
	void OnMouseOver(int x, int y);
	void OnMouseAway(int x, int y);
	void OnMousePress(int x, int y);
	void OnMouseRelease(int x, int y);
	void OnMouseClick(int x, int y);
};

