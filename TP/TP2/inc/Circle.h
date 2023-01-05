#pragma once

#include "Point.h"

#define PI 3.141592

class Circle
{
	private:
		double diameter;
		Point center;

	public:
		
		Circle(double diameter, Point center) : diameter(diameter), center(center) {}

		~Circle();

		inline void setDiameter(double d) { diameter = d; }

		void setCenter(Point p) { center = p; }

		inline double getDiameter() const { return diameter; }

		Point getCenter() const { return center; }

		inline double perimeter() const { return PI * diameter; }

		inline double area() const { return PI * (diameter / 2) * (diameter / 2); }

		bool isOn(Point p);

		bool isIn(Point p);

		void afficher();
};