#include <iostream>
#include <cmath>
#include "point2d.h"
using namespace std;

Point2D::Point2D()
{
    x=0;
    y=0;
}

Point2D::Point2D(double x,double y)
{
    this->x=x;
    this->y=y;
}

double Point2D::getX() const
{
    return x;
}

double Point2D::getY() const
{
    return y;
}

double Point2D::distance() const
{
    return sqrt(getX()*getX()+getY()*getY());
}

double Point2D::distance(Point2D point) const
{
    point.reflect();
    point.translate(*this);
    return point.distance();
}

void Point2D::print() const
{
    cout<<'('<<x<<','<<y<<')';
}

void Point2D::setX(double x)
{
    this->x=x;
}

void Point2D::setY(double y)
{
    this->y=y;
}

void Point2D::translate(const Point2D& point)
{
    x+=point.x;
    y+=point.y;
}

void Point2D::reflectX()
{
    setX(-getX());
}

void Point2D::reflectY()
{
    setY(-getY());
}

void Point2D::reflect()
{
    reflectX();
    reflectY();
}
