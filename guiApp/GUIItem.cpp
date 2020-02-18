#include "GUIItem.h"
#include "Renderer.h"
#include <iostream>

GUIItem::GUIItem()
{
	// default color for a new GUIItem
	color = Color(0.6f, 0.6f, 0.7f);

	// renderer -> null
	m_renderer = NULL;

	// Creates a Size Vector
	m_size = Vector2D();

	// Creates a Position Vector
	m_position = Vector2D(0.0f, 0.0f);

	// Creates an offset Vector
	m_offset = Vector2D(0.0f, 0.0f);

	// GUIItem is visible (not hidden) by default
	is_hidden = false;
}

bool GUIItem::hasRenderer()
{
	return m_renderer != NULL;
}

void GUIItem::hide()
{
	is_hidden = true;
}

void GUIItem::show()
{
	is_hidden = false;
}

GUIItem::~GUIItem()
{
	//Q: Can you delete m_renderable if the renderable is shared by other GUI items?
	//A: The m_renderable can be erased only if it's sharing_counter is 1.
	if (m_renderer != NULL)
	{
		if (m_renderer->SharingCounter() == 1)
		{
			delete(m_renderer);
		}
		else
		{
			m_renderer->DecreaseCounter();
		}
	}
}

float GUIItem::GetX()
{
	// return the absolute position's X value
	// that is the relative (m_position) + offset
	return m_position.GetX() + m_offset.GetX();
}

float GUIItem::GetY()
{
	// return the absolute position's Y value
	// that is the relative (m_position) + offset
	return m_position.GetY() + m_offset.GetY();
}

void GUIItem::SetX(float x)
{
	// set relative X
	return m_position.SetX(x);
}

void GUIItem::SetY(float y)
{
	// set relative Y
	return m_position.SetY(y);
}

Vector2D GUIItem::GetAbsolutePosition()
{
	// get absolute position -> offset + relative position
	return m_position+m_offset;
}

Vector2D GUIItem::GetOffset()
{
	// get offset
	return m_offset;
}

Vector2D GUIItem::GetRelativePosition()
{
	// get relative position
	return m_position;
}

void GUIItem::SetPosition(float x, float y)
{
	// set position
	m_position.SetX(x);
	m_position.SetY(y);
}

Vector2D GUIItem::GetSize(void)
{
	// get safely the size
	return Vector2D(m_size);
}

void GUIItem::SetSize(float x, float y)
{
	// set size
	m_size.SetX(x);
	m_size.SetY(y);
}

void GUIItem::SetOffset(float x, float y)
{
	// set offset
	m_offset.SetX(x);
	m_offset.SetY(y);
}

bool GUIItem::isSelected(int x, int y)
{
	// _height -> renderer's height
	int _height = m_renderer->getHeight();

	// invert the y axis, because OpenGL is using a different coordinate system
	y = _height - y;

	// item's x position
	float item_x = GetX();

	// item's y position
	float item_y = _height - GetY();

	// item's x size
	float size_x = GetSize().GetX();

	// item's y size
	float size_y = GetSize().GetY();

	// if ( x > item's x )
	// and if ( x < item's x + item's x size )
	// and if ( y < item's y )						(measuring y bottom-up)
	// and if ( y > item's y - item's y size )		(measuring y bottom-up)
	//	-> then return true
	//  -> else false
	if (x >= item_x && y < item_y && x < item_x+size_x && y >= item_y-size_y)
		return true;
	else return false;
}

void GUIItem::SetColor ( float r, float g, float b )
{
	// set color
	color.SetColor(r, g, b);
}
Color GUIItem::GetColor()
{
	// safely get color
	return Color(color);
}
