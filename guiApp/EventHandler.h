#pragma once

// Base class of event handlers
class EventHandler
{
public:
	virtual void OnMouseOver(int x, int y) = 0;
	virtual void OnMouseAway(int x, int y) = 0;
	virtual void OnMousePress(int x, int y) = 0;
	virtual void OnMouseRelease(int x, int y) = 0;
	virtual void OnMouseClick(int x, int y) = 0;
};