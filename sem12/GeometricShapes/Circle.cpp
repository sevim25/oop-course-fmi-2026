#include "Circle.h"
#include <stdexcept>

std::string Circle::name() const
{
	return "Circle";
}

std::unique_ptr<Shape> Circle::clone() const
{
	return std::make_unique<Circle>(*this);
}

Circle::Circle(double r, const Point& c) : center(c)
{
	setRadius(r);
}

void Circle::setRadius(double r)
{
	if (r <= 0) {
		throw std::invalid_argument("Radius must be positive");
	}

	this->r = r;
}

double Circle::area() const
{
	return PI * r * r;
}

double Circle::perimeter() const
{
	return 2 * PI * r;
}

bool Circle::isInside(const Point& point) const
{
	return (point.x - center.x) * (point.x - center.x)
		+  (point.y - center.y) * (point.y - center.y) <= r * r;
}
