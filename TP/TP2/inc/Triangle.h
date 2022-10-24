#pragma once

#include <math.h>

#include "Point.h"

class Triangle
{
	private:
		Point p1;
		Point p2;
		Point p3;

	public:
		Triangle(Point p1, Point p2, Point p3);

		~Triangle();

		float base();

		float height();

		void sides(float& p1p2, float& p2p3, float& p3p1);

		bool isIsosceles();

		bool isRectangle();

		bool isEquilateral();
};