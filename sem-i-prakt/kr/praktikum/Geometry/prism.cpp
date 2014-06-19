#include "prism.h"

StraightDiamondPrism::StraightDiamondPrism(double baseSide = 0, double baseAngle = 0, double height = 0):
        StraightBody(height), Diamond(baseSide, baseAngle) {}

double StraightDiamondPrism::getTotalSurfaceArea() const
{
    return Diamond::getArea() * height;
}

double StraightDiamondPrism::getVolume() const
{
    return 2 * Diamond::getArea() + Diamond::getPerimeter() * height;
}

std::ostream& operator<<(std::ostream& os, const StraightDiamondPrism& d)
{
    os << "== Straight diamond prism ==" << std::endl;
    //os << "Side: " << side << std::endl;
    //os << "Angle (in radians): " << angle << std::endl;
    os << "Base side: " << d.Diamond::getSide() << std::endl;
    os << "Base angle: " << d.Diamond::getAngle() << std::endl;
    operator<<(os, d);
    os << "Base perimeter: " << d.Diamond::getPerimeter() << std::endl;
    os << "Base area: " << d.Diamond::getArea() << std::endl;
    os << "Total surface area: " << d.getTotalSurfaceArea() << std::endl;
    os << "Volume: " << d.getVolume() << std::endl;
    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, StraightDiamondPrism& d)
{
    double baseSide, baseAngle;
    is >> baseSide >> baseAngle;
    operator>>(is, d);
    d.Diamond::setSide(baseSide);
    d.Diamond::setAngle(baseAngle);
    return is;
}
