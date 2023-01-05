#include "../inc/Circle.h"

Circle::~Circle()
{
	delete& center;
}

bool Circle::isOn(Point p)
{
	double distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));

	if (distance == diameter / 2)
		return true;
	else
		return false;
}

bool Circle::isIn(Point p)
{
	double distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));

	if (distance < diameter / 2)
		return true;
	else
		return false;
}

void Circle::afficher()
{
	std::cout << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
	std::cout << "Diameter: " << diameter << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Options :\n\tGetters/Setters\n\tAire\n\tPérimètre\n\tPoint sur ou dans le cercle" << std::endl;
}