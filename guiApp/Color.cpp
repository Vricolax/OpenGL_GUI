#include "Color.h"
#include <iostream>

// default color (black)
Color::Color() {
	r = g = b = 0;
}

// constructor
Color::Color(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

// duplicate constructor
Color::Color(const Color &color)
{
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
}

// sets new color from a given rgb
void Color::SetColor(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

//get red
float Color::GetRed() {
	return this->r;
}

// get green
float Color::GetGreen() {
	return this->g;
}

//get blue
float Color::GetBlue() {
	return this->b;
}

Color::~Color(void)
{
}
