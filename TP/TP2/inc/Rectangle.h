#pragma once

#include "Point.h"

class Rectangle
{
	private:
		double height;
		double width;
		Point origin;

	public:

		Rectangle(const double height, const double width, const Point origin)
			: height(height), width(width), origin(origin) {}

		~Rectangle();

		inline void setHeight(double h) { height = h; };

		inline void setWidth(double w) { width = w; };

		void setOrigin(Point p) { origin = p; }

		inline double getHeight() const { return height; };

		inline double getWidth() const { return width; };

		Point getOrigin() { return origin; };

		inline double perimeter() const { return (height + width) * 2; };

		inline double area() const { return height * width; };

		bool hasBiggerPerimeter(Rectangle r);

		bool hasBiggerArea(Rectangle r);

		void afficher();
};