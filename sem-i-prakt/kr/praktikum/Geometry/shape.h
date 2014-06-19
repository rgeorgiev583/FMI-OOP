#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <iostream>

class Shape
{
public:
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape();

    friend std::ostream& operator<<(std::ostream&, const Shape&);
    friend std::istream& operator>>(std::istream&, Shape&);
};

#endif // SHAPE_H_INCLUDED
