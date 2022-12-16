#include "../inc/Rectangle.h"

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


void Rectangle::afficher()
{
	std::cout << "Rectangle: " << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Origin: " << origin.x << " " << origin.y << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Options :\n\tPérimètre\n\tAire\n\tComparaisons entre 2 rectangles" << std::endl;
}