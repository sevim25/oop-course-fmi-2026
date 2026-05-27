#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	Point point1;
	Point point2;

	double w;
	double h;

public:
	Rectangle(double w, double h, const Point& p1, const Point& p2);

	void setWidth(double w);
	void setHeight(double h);

	double area() const override;
	double perimeter() const override;
	bool isInside(const Point& point) const override;

	std::string name() const override;

	std::unique_ptr<Shape> clone() const override;

};

