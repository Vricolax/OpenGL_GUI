#pragma once
#include "GUIItem.h"
#include "Vector2D.h"
#include "Color.h"

class Label : public GUIItem
{
private:
	//Label string
	char *text;
	//Color of the label
	Color color;
public:
	Label(void);
	Label(char* text);
	Label(const Label &label);
	~Label(void);

	//Draw the label
	void draw();

	//Set a renderer to the label
	void SetRenderer(Renderer *renderer);

	//Mouse actions
	bool MouseMove ( int x, int y );
	bool MouseLBDown ( int x, int y );
	bool MouseLBUp ( int x, int y );

	//Return the text of the label
	char* GetText();

	//Return the Color (r,b,g) of the label
	Color GetColor();

	//Set a new color to the label
	void SetColor(float r, float g, float b);

	//Return the characters length of the label's string
	int Length();

	//Return the size of the label (width, height)
	Vector2D GetSize(void);
};

