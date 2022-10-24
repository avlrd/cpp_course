#include "..\inc\Triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

Triangle::~Triangle()
{
}

void Triangle::sides(float& p1p2, float& p2p3, float& p3p1)
{
	p1p2 = distance(p1, p2);
	p2p3 = distance(p2, p3);
	p3p1 = distance(p3, p1);
}

bool Triangle::isIsosceles()
{
	float p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 == p2p3 || p2p3 == p3p1 || p3p1 == p1p2)
		return true;
	else
		return false;
}

bool Triangle::isRectangle()
{
	float p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 * p1p2 + p2p3 * p2p3 == p3p1 * p3p1 || p2p3 * p2p3 + p3p1 * p3p1 == p1p2 * p1p2 || p3p1 * p3p1 + p1p2 * p1p2 == p2p3 * p2p3)
		return true;
	else
		return false;
}

bool Triangle::isEquilateral()
{
	float p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 == p2p3 && p2p3 == p3p1)
		return true;
	else
		return false;
}

float Triangle::base()
{
	float p1p2, p2p3, p3p1;
	sides(p1p2, p2p3, p3p1);
	if (p1p2 > p2p3 && p1p2 > p3p1)
		return p1p2;
	else if (p2p3 > p1p2 && p2p3 > p3p1)
		return p2p3;
	else
		return p3p1;
}