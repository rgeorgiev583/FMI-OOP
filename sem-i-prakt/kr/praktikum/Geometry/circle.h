#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "shape.h"

class Circle: public Shape
{
    double radius;

public:
    Circle(double = 0);

    double getRadius() const;
    double getPerimeter() const;
    double getArea() const;

    void setRadius(double);

    friend std::ostream& operator<<(std::ostream&, const Circle&);
    friend std::istream& operator>>(std::istream&, Circle&);
};

#endif // CIRCLE_H_INCLUDED
