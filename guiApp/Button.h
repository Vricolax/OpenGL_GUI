#pragma once
#include "GUIItem.h"
#include "Label.h"
#include "Vector2D.h"
#include "EventHandler.h"

class Button: public GUIItem
{
private:
	//Button's text
	Label label;
	//handler that handles the mouse events
	EventHandler *handler;
public:
	Button(void);
	Button(Label &label, float x, float y);
	Button(const Button &button);
	~Button(void);

	//Event generators
	bool MouseMove ( int x, int y );
	bool MouseLBDown ( int x, int y );
	bool MouseLBUp ( int x, int y );

	//Set a handler for the button
	void SetEventHandler(EventHandler *handler);
	
	//Draw the button
	void draw();

	//Set a renderer to the button
	void SetRenderer(Renderer *renderer);

	//Return the button's text
	Label GetLabel();

	//Return the size of the button (width,height)
	Vector2D GetSize(void);
};

