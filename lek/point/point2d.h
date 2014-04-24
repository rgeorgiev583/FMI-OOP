#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

class Point2D
{
    double x,y;
public:
    Point2D();
    Point2D(double,double);

    double getX() const;
    double getY() const;
    double distance() const;
    double distance(Point2D P) const;
    void print() const;

    void setX(double);
    void setY(double);
    void translate(const Point2D& P);
    void reflectX();
    void reflectY();
    void reflect();
};

#endif // POINT2D_H_INCLUDED
