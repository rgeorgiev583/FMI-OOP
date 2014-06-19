#include <cmath>

#include "circle.h"

Circle::Circle(double _radius = 0): radius(_radius) {}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

void Circle::setRadius(double _radius)
{
    radius = _radius;
}

std::ostream& operator<<(std::ostream& os, const Circle& d)
{
    os << "== Circle ==" << std::endl;
    os << "Radius: " << d.radius << std::endl;
    os << "Perimeter: " << d.getPerimeter() << std::endl;
    os << "Area: " << d.getArea() << std::endl;
    os << std::endl;
}

std::istream& operator>>(std::istream& is, Circle& d)
{
    is >> d.radius;
}
