#include "Triangle.h"
#include <stdexcept>

std::string Triangle::name() const
{
	return "Triangle"; 
}

std::unique_ptr<Shape> Triangle::clone() const
{
	return std::make_unique<Triangle>(*this);
}

double Triangle::dist(const Point& p1, const Point& p2)
{
	double distance2 = (p1.x - p2.x) * (p1.x - p2.x)
					 + (p1.y - p2.y) * (p1.y - p2.y);
	return std::sqrt(distance2);
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
	: p1(a),p2(b),p3(c) {}


double Triangle::perimeter() const
{
	return dist(p1, p2) + dist(p2, p3) + dist(p1, p3);
}

double Triangle::area() const
{
	return std::abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;
}

double Triangle::area(const Point& a, const Point& b, const Point& c) const
{
	return std::abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2;
}

bool Triangle::isInside(const Point& point) const
{
	double s = area();
	double s1 = area(p1, p2, point);
	double s2 = area(p2, p3, point);
	double s3 = area(p1, p3, point);

	const double EPSILON = 1e-9;
	return std::abs(s - (s1 + s2 + s3)) < EPSILON;
}

