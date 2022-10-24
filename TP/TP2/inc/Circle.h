#pragma once

#include "Point.h"

#define PI 3.141592

class Circle
{
	private:
		int diameter;
		Point center;

	public:
		/*
		* @brief Constructor
		*/
		Circle(int diameter, Point center);

		/*
		* @brief Destructor
		*/
		~Circle();

		/*
		* @brief Sets the diameter of the circle.
		* @param int d
		*/
		inline void setDiameter(int d) { diameter = d; }

		/*
		* @brief Sets the center of the circle.
		* @param Point p
		*/
		void setCenter(Point p) { center = p; }

		/*
		* @brief Returns the diameter of the circle.
		*/
		inline int getDiameter() const { return diameter; }

		/*
		* @brief Returns the center of the circle.
		*/
		Point getCenter() const { return center; }

		/*
		* @brief Returns the perimeter of the circle.
		*/
		inline float perimeter() const { return PI * diameter; }

		/*
		* @brief Returns the area of the circle.
		*/
		inline float area() const { return PI * (diameter / 2) * (diameter / 2); }

		/*
		* @brief Checks if the point is on this circle.
		* @param Point p
		*/
		bool isOn(Point p);

		/*
		* @brief Checks if the point is in the circle (strictly).
		* @param Point p
		*/
		bool isIn(Point p);
};