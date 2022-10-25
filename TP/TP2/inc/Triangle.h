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
		Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {}

		~Triangle() {};
		
		inline double area() const { return (base() * height()) / 2; }

		double base();

		inline double height() const {return (2 * area()) / base()};

		void sides(double& p1p2, double& p2p3, double& p3p1);

		bool isIsosceles();

		bool isRectangle();

		bool isEquilateral();

		void afficher();
};