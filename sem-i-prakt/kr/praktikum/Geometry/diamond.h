#ifndef DIAMOND_H_INCLUDED
#define DIAMOND_H_INCLUDED

#include "shape.h"

class Diamond: public Shape
{
    double side, angle;//, apothema;

public:
    Diamond(double = 0, double = 0);

    double getSide() const;
    double getAngle() const;
    double getPerimeter() const;
    double getArea() const;
    double getArea(bool) const;

    void setSide(double);
    void setAngle(double);

    friend std::ostream& operator<<(std::ostream&, const Diamond&);
    friend std::istream& operator>>(std::istream&, Diamond&);
};

#endif // DIAMOND_H_INCLUDED
