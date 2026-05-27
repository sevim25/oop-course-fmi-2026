#pragma once
#include <iostream>
#include <memory>

struct Point {
	double x;
	double y;
};

class Shape
{
public:

	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual bool isInside(const Point& point) const = 0;
	virtual std::string name() const = 0;

	virtual std::unique_ptr<Shape> clone() const = 0;

	virtual ~Shape() = default;

};

