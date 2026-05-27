#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	Point p1;
	Point p2;
	Point p3;

	static double dist(const Point& p1, const Point& p2);

public:
	Triangle(const Point& a, const Point& b, const Point& c );

	double perimeter() const override;

	double area() const override;
	double area(const Point& a, const Point& b, const Point& c) const;

	bool isInside(const Point& point) const override;
	std::string name() const override;

	std::unique_ptr<Shape> clone() const override;
};

