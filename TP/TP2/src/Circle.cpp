#include "../inc/Circle.h"

Circle::Circle(int diameter, Point center)
{
	this->diameter = diameter;
	this->center = center;
}

Circle::~Circle()
{
	delete& center;
}

bool Circle::isOn(Point p)
{
	float distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));

	if (distance == diameter / 2)
		return true;
	else
		return false;
}

bool Circle::isIn(Point p)
{
	float distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));

	if (distance < diameter / 2)
		return true;
	else
		return false;
}
