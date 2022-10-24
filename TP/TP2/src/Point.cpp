#include "../inc/Point.h";

float distance(Point p1, Point p2)
{
	float x = p1.x - p2.x;
	float y = p1.y - p2.y;
	return sqrt(x * x + y * y);
}