#include <iostream>

#include "../inc/Point.h"
#include "../inc/Circle.h"
#include "../inc/Triangle.h"
#include "../inc/Rectangle.h"

int main()
{
	//Rectangle
	Point pr{ 1, 1 };
	Rectangle rect(2, 3, pr);
	Rectangle biggerRect(2, 6, pr);
	std::cout << "Rectangle area: " << rect.area() << std::endl;
	std::cout << "Rectangle perimeter: " << rect.perimeter() << std::endl;
	std::cout << "Rectangle has bigger area than biggerRect: " << rect.hasBiggerArea(biggerRect) << std::endl;
	std::cout << "Rectangle has bigger perimeter than biggerRect: " << rect.hasBiggerPerimeter(biggerRect) << std::endl;
	std::cout << "biggerRectangle has bigger perimeter than Rectangle: " << biggerRect.hasBiggerPerimeter(rect) << std::endl;
	

	//Circle
	Point pc{ 2, 2 };
	Point test1{ 2,3 };
	Point test2{ 4,2 };
	Circle circle(2, pc);
	std::cout << "Circle area: " << circle.area() << std::endl;
	std::cout << "Circle perimeter: " << circle.perimeter() << std::endl;
	std::cout << "Point test1 is in circle ? " << circle.isIn(test1) << std::endl;
	std::cout << "Point test2 is on circle ? " << circle.isOn(test2) << std::endl;

	//Triangle
	Point pt1{ 1, 1 };
	Point pt2{ 2, 2 };
	Point pt3{ 3, 3 };
	Triangle triangle(pt1, pt2, pt3);
	std::cout << "Triangle is isosceles ? " << triangle.isIsosceles() << std::endl;
	std::cout << "Triangle is rectangle ? " << triangle.isRectangle() << std::endl;
	std::cout << "Triangle is equilateral ? " << triangle.isEquilateral() << std::endl;
	
	return 0;
}