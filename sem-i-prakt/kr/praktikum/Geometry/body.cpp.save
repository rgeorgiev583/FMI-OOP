#include "prism.h"

double StraightBody::getHeight() const
{
    return height;
}

void StraightBody::setHeight(double _height)
{
    height = _height;
}

std::ostream& operator<<(std::ostream& os, const StraightBody& sb)
{
    os << "Height: " << sb.height << std::endl;
}

std::istream& operator>>(std::istream& is, StraightBody& sb)
{
    is >> sb.height;
}
