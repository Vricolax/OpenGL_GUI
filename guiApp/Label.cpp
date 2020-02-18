#include <iostream>
#include "Label.h"
#include "Renderer.h"
#include "Color.h"

// default constructor
Label::Label(void)
{
	this->text = "";
	SetX(0);
	SetY(0);
	color = Color(0.1f,0.1f,0.1f);
}

// create labe with some text
Label::Label(char* text)
{
	// get text's pointer
	this->text = text;

	// set default position to (0,0)
	SetX(0);
	SetY(0);
	
	// set default color to dark gray
	color = Color(0.1f,0.1f,0.1f);
}


//duplicate constructor
Label::Label(const Label &label)
{
	this->text = label.text;
	this->color = Color(label.color);
	m_position = Vector2D(label.m_position);
	m_offset = Vector2D(label.m_offset);
	m_size = Vector2D(label.m_size);
	SetRenderer(label.m_renderer);
}

bool Label::MouseMove ( int x, int y )
{
	// no implementation needed
	return false;
}
bool Label::MouseLBDown ( int x, int y )
{
	// no implementation needed
	return false;
}
bool Label::MouseLBUp ( int x, int y )
{
	// no implementation needed
	return false;
}

void Label::SetRenderer(Renderer *renderer)
{
	// set renderer
	if (renderer != NULL)
	{
		m_renderer = renderer;
		m_renderer->IncreaseCounter();
	}
}

Label::~Label(void)
{
}

void Label::draw()
{
	// draw
	if (m_renderer)
		m_renderer->draw(this);
}

Vector2D Label::GetSize(void)
{
	// get approximate size of text
	// size_x <- power ( Length(), 0.7 ) * 25
	m_size.SetX(powf((float)Length(), 0.7f) * 25.0f);
	
	// set height of text to 35, experimentally acquired
	m_size.SetY(35.0f);

	// safely return size
	return Vector2D(m_size);
}

void Label::SetColor(float r, float g, float b) {

	// set color
	this->color.SetColor(r, g, b);
}

char* Label::GetText()
{
	// get text
	return text;
}

Color Label::GetColor()
{
	// safely get color
	return Color(color);
}

int Label::Length() {
	
	// length of text	<-	from i to inf, until char != NULL
	int length = 0;
	for (int i = 0; text[i] != '\0'; i ++)
		length ++;

	// return length
	return length;
}