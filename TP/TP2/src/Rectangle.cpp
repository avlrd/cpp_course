#include "../inc/Rectangle.h"

Rectangle::Rectangle(const int height, const int width, const Point origin)
{
	this->height = height;
	this->width = width;
	this->origin = origin;
}

Rectangle::~Rectangle()
{
	delete &origin;
}

bool Rectangle::hasBiggerPerimeter(Rectangle r)
{
	if (this->perimeter() > r.perimeter())
		return true;
	return false;
}

bool Rectangle::hasBiggerArea(Rectangle r)
{
	if (this->area() > r.area())
		return true;
	return false;
}


