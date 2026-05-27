#include "Rectangle.h"
#include <stdexcept>

std::string Rectangle::name() const
{
	return "Rectangle";
}

std::unique_ptr<Shape> Rectangle::clone() const
{
	return std::make_unique<Rectangle>(*this);
}

Rectangle::Rectangle(double w, double h, const Point& p1, const Point& p2 )
	: point1(p1), point2(p2)
{
	setWidth(w);
	setHeight(h);
}

void Rectangle::setWidth(double w)
{
	if (w <= 0) {
		throw std::invalid_argument("Width must be positive");
	}

	this->w = w;
}

void Rectangle::setHeight(double h)
{
	if (h <= 0) {
		throw std::invalid_argument("Height must be positive");
	}

	this->h = h;
}

double Rectangle::area() const
{
	return w * h;
}

double Rectangle::perimeter() const
{
	return (2 * h) + (2 * w);
}

bool Rectangle::isInside(const Point& point) const
{
	return point.x >= point1.x && point.x <= point2.x
		&& point.y >= point1.y && point.y <= point2.y;
}

