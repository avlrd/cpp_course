#include "..\inc\Triangle.h"

void Triangle::sides(double& p1p2, double& p2p3, double& p3p1)
{
	p1p2 = distance(p1, p2);
	p2p3 = distance(p2, p3);
	p3p1 = distance(p3, p1);
}

bool Triangle::isIsosceles()
{
	double p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 == p2p3 || p2p3 == p3p1 || p3p1 == p1p2)
		return true;
	else
		return false;
}

bool Triangle::isRectangle()
{
	double p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 * p1p2 + p2p3 * p2p3 == p3p1 * p3p1 || p2p3 * p2p3 + p3p1 * p3p1 == p1p2 * p1p2 || p3p1 * p3p1 + p1p2 * p1p2 == p2p3 * p2p3)
		return true;
	else
		return false;
}

bool Triangle::isEquilateral()
{
	double p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 == p2p3 && p2p3 == p3p1)
		return true;
	else
		return false;
}

double Triangle::base()
{
	double p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 > p2p3 && p1p2 > p3p1)
		return p1p2;
	else if (p2p3 > p1p2 && p2p3 > p3p1)
		return p2p3;
	else
		return p3p1;
}

void Triangle::afficher()
{
	std::cout << "Triangle: " << std::endl;
	std::cout << "Point 1: " << p1 << std::endl;
	std::cout << "Point 2: " << p2 << std::endl;
	std::cout << "Point 3: " << p3 << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Options :\n\tAire\n\tBase\n\tHauteur\n\tCôtés\n\tVérifications de type de triangle" << std::endl;
}