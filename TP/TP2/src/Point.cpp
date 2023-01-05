#include "../inc/Point.h";

double distance(Point p1, Point p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	return sqrt(x * x + y * y);
}