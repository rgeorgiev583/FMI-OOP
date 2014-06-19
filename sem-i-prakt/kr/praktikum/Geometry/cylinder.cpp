#include "cylinder.h"

StraightCircularCylinder::StraightCircularCylinder(double baseRadius = 0,
        double height = 0): StraightBody(height), Circle(baseRadius) {}

double StraightCircularCylinder::getTotalSurfaceArea() const
{
    return Circle::getArea() * height;
}

double StraightCircularCylinder::getVolume() const
{
    return 2 * Circle::getArea() + Circle::getPerimeter() * height;
}

std::ostream& operator<<(std::ostream& os, const StraightCircularCylinder& c)
{
    os << "== Straight diamond prism ==" << std::endl;
    //os << "Side: " << side << std::endl;
    //os << "Angle (in radians): " << angle << std::endl;
    os << "Base radius: " << c.Circle::getRadius() << std::endl;
    operator<<(os, c);
    os << "Base perimeter: " << c.Circle::getPerimeter() << std::endl;
    os << "Base area: " << c.Circle::getArea() << std::endl;
    os << "Total surface area: " << c.getTotalSurfaceArea() << std::endl;
    os << "Volume: " << c.getVolume() << std::endl;
    os << std::endl;
}

std::istream& operator>>(std::istream& is, StraightCircularCylinder& c)
{
    double baseRadius;
    is >> baseRadius;
    operator>>(is, c);
    c.Circle::setRadius(baseRadius);
}
