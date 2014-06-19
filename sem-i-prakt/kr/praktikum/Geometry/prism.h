#ifndef PRISM_H_INCLUDED
#define PRISM_H_INCLUDED

#include "body.h"
#include "diamond.h"

class StraightDiamondPrism: public StraightBody, protected Diamond
{
public:
    StraightDiamondPrism(double = 0, double = 0, double = 0);

    double getTotalSurfaceArea() const;
    double getVolume() const;

    friend std::ostream& operator<<(std::ostream&, const StraightDiamondPrism&);
    friend std::istream& operator>>(std::istream&, StraightDiamondPrism&);
};

#endif // PRISM_H_INCLUDED
