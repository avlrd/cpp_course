#pragma once

#include "Point.h"

/*
* A rectangle contains its width and height
*/
class Rectangle
{
	private:
		int height;
		int width;
		Point origin;

	public:
		/*
		* @brief Constructor
		* @param const int height
		* @param const int width
		* @param const Point origin
		*/
		Rectangle(const int height, const int width, const Point origin);

		/*
		* @brief Destructor
		*/
		~Rectangle();

		/*
		* @brief Sets the height of the rectangle.
		* @param int h
		*/
		inline void setHeight(int h) { height = h; };

		/*
		* @brief Sets the width of the rectangle.
		* @param int w
		*/
		inline void setWidth(int w) { width = w; };

		/*
		* @brief Sets the origin (top left corner) of the rectangle.
		* @param Point p
		*/
		void setOrigin(Point p) { origin = p; }

		/*
		* @brief Returns the height of the rectangle.
		*/
		inline int getHeight() const { return height; };

		/*
		* @brief Returns the width of the rectangle.
		*/
		inline int getWidth() const { return width; };

		/*
		* @brief Returns the origin (top left corner) of the rectangle.
		*/
		Point getOrigin() { return origin; };

		/*
		* @brief Returns the perimeter of the rectangle.
		*/
		inline float perimeter() const { return (height + width) * 2; };

		/*
		* @brief Returns the area of the rectangle.
		*/
		inline float area() const { return height * width; };

		/*
		* @brief Returns true if this rectangle is bigger than r.
		* @param Rectangle r
		*/
		bool hasBiggerPerimeter(Rectangle r);

		/*
		* @brief Returns true if this rectangle is bigger than r.
		* @param Rectangle r
		*/
		bool hasBiggerArea(Rectangle r);
};