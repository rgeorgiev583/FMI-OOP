#include <cmath>

#include "diamond.h"

Diamond::Diamond(double _side = 0, double _angle = 0):
        side(_side), angle(_angle) {}

double Diamond::getSide() const
{
    return side;
}

double Diamond::getAngle() const
{
    return angle;
}

double Diamond::getPerimeter() const
{
    return 4 * side;
}

double Diamond::getArea() const
{
    return side * side * sin(angle);
}

/* // using height
double Diamond::getArea() const
{
    return side * height;
}
*/

void Diamond::setSide(double _side)
{
    side = _side;
}

void Diamond::setAngle(double _angle)
{
    angle = _angle;
}

std::ostream& operator<<(std::ostream& os, const Diamond& d)
{
    os << "== Diamond ==" << std::endl;
    os << "Side: " << d.side << std::endl;
    os << "Angle (in radians): " << d.angle << std::endl;
    os << "Perimeter: " << d.getPerimeter() << std::endl;
    os << "Area: " << d.getArea() << std::endl;
    os << std::endl;
}

std::istream& operator>>(std::istream& is, Diamond& d)
{
    is >> d.side >> d.angle;
}
