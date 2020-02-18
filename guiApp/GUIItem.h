#pragma once
// in order to prevent recursive compilation
class Renderer;
#include "Listener.h"
#include "Color.h"
#include <vector>
#include "Vector2D.h"

//Base class of a GUI item

class GUIItem : public Listener
{
protected:
	Color			color;
	bool			down, mousePressed, is_hidden;
	Vector2D		m_position, m_offset, m_size;
	Renderer*		m_renderer; //the renderer of this GUI item, should be shared
public:
	GUIItem();
	virtual ~GUIItem();

	//Event Generators to be implemented by the subclass
	virtual bool MouseMove ( int x, int y ) = 0;
	virtual bool MouseLBDown ( int x, int y ) = 0;
	virtual bool MouseLBUp ( int x, int y ) = 0;

	// to be implemented by the subclass
	virtual void draw() = 0;

	//Hide the guiitem
	void hide();

	//Show the guiitem
	void show();

	//Return whether the gui item if hidden or not
	bool isHidden() { return is_hidden; }

	// to be implemented by the subclass
	virtual void SetRenderer(Renderer *renderer) = 0;
	
	//Return whether the guiitem has a renderer or not
	bool hasRenderer();

	//Return whether the mouse is hovering over this guiitem
	bool isSelected(int x, int y);

	//Return whether the gui item is clicked
	virtual bool isPressed()
	{
		return mousePressed;
	};

	//Set a new color to the gui item
	void SetColor( float r, float g, float b );

	//Return the color of the gui item
	Color GetColor();

	//Return the position of the gui item (x,y)
	Vector2D GetRelativePosition(void);
	Vector2D GetAbsolutePosition(void);
	Vector2D GetOffset(void);

	//Return the size of the gui item (width, height)
	Vector2D GetSize(void);

	//Set a new position to the gui item
	void SetPosition(float x, float y);

	//Set a new size to the gui item
	void SetSize(float width, float height);

	//Set an offset to the gui item
	void SetOffset(float x, float y);

	//Return the gui item's coordinates
	float GetX();
	float GetY();

	//Set new coordinates to the gui item
	void SetX(float x);
	void SetY(float y);
};
