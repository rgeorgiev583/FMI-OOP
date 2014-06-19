#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED

#include <iostream>

#include "shape.h"

class StraightBody
{
protected:
    double height;

public:
    StraightBody(double = 0);

    double getHeight() const;
    double getTotalSurfaceArea() const;
    double getVolume() const;
    virtual ~StraightBody();

    void setHeight(double);

    friend std::ostream& operator<<(std::ostream&, const StraightBody&);
    friend std::istream& operator>>(std::istream&, StraightBody&);
};

#endif // BODY_H_INCLUDED
