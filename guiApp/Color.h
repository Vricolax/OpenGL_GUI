#pragma once
class Color
{
private:
	//Color arguments: r = red, g = green, b = blue
	float r, g, b;
public:
	Color();
	Color(float r, float g, float b);
	Color(const Color &color);
	~Color(void);

	//Set new color for an object
	void SetColor(float r, float g, float b);

	//Return the Color arguments
	float GetRed();
	float GetGreen();
	float GetBlue();
};

