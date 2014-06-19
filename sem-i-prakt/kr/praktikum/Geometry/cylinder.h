#ifndef CYLINDER_H_INCLUDED
#define CYLINDER_H_INCLUDED

#include "body.h"
#include "circle.h"

class StraightCircularCylinder: public StraightBody, protected Circle
{
public:
    StraightCircularCylinder(double = 0, double = 0);

    double getTotalSurfaceArea() const;
    double getVolume() const;

    friend std::ostream& operator<<(std::ostream&, const StraightCircularCylinder&);
    friend std::istream& operator>>(std::istream&, StraightCircularCylinder&);
};

#endif // CYLINDER_H_INCLUDED
