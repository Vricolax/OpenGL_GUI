#pragma once
#include "GUIItem.h"
#include "Selection.h"
#include "Vector2D.h"
#include "Label.h"

class Menu : public GUIItem
{
private:
	//state of the menu -> true : folded
	//					-> false : expanded
	bool is_folded;
	//Width of the selections
	float selection_width;
	//the selections
	std::vector<Selection*> m_selections;
	//Menu Title
	Label title;
public:
	Menu(Label &title, float x, float y, float width, float height);
	~Menu(void);
	
	//Mouse actions
	bool MouseMove ( int x, int y );
	bool MouseLBDown ( int x, int y );
	bool MouseLBUp ( int x, int y );
	
	//Return whether the menu expands any selection or not 
	bool isFolded();

	//Return whether the menu is pressed ot not
	bool isPressed();

	//Draw the menu
	void draw();

	//Set a width for the selection
	void SetSelectionWidth(float width);

	//Return the width of the selection
	float GetSelectionWidth();

	//Return the menu title
	Label GetTitle();

	//Add a selection to the menu
	void AddSelection(Selection *selection);

	//Return the selections
	std::vector<Selection*> GetSelections(void);

	//Set a renderer to the selection
	void SetRenderer(Renderer *renderer);
};

