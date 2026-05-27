#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double r;
	Point center;
	static constexpr double PI = 3.14;

public:
	Circle(double r, const Point& c);

	void setRadius(double r);

	double area() const override;
	double perimeter() const override;
	bool isInside(const Point& point) const override;

	std::string name() const override;

	std::unique_ptr<Shape> clone() const override;
};

