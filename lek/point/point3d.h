#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

class Point3D
{
    Point2D p;
    double z;
public:
    Point3D();
    Point3D(Point2D,double);

    Point2D getP() const;
    double getZ() const;
    double distance() const;
    double distance(Point3D) const;
    void print() const;

    void setP(Point2D);
    void setZ(double);
};

#endif // POINT3D_H_INCLUDED
