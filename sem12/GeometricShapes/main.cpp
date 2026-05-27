#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void printInfo(const Shape& shape, const Point& p) {
    std::cout << "--- " << shape.name() << " ---\n";
    std::cout << "Area: " << shape.area() << '\n';
    std::cout << "Perimeter: " << shape.perimeter() << '\n';
    std::cout << "Is inside P(" << p.x << ", " << p.y << "): ";

    if (shape.isInside(p)) {
        std::cout << "Yes\n";
    }
    else {
        std::cout << "No\n";
    }

    std::cout << '\n';
}

int main()
{
    Point A{ 0, 0 };
    Point B{ 6, 0 };
    Point C{3, 5};

    Point p{ 3,2 };

    Triangle triangle(A, B, C);
    printInfo(triangle, p);

    Rectangle rec(4, 6, B, C);
    printInfo(rec, p);

    Circle circle(5, A);
    printInfo(circle, p);
}
