#include <iostream>
#include "vector.h"
#include "vector3d.h"

using namespace std;

void printInfoAboutVector(const Vector& v)
{
    cout << "X = " << v.getX() << endl;
    cout << "Y = " << v.getY() << endl;
    cout << "isNull = " << (v.isNull() ? "True" : "False") << endl;
    cout << "length = " << v.length() << endl;
    cout << "normalized: ";
    v.normalized().print();
    cout << endl;
}

void printInfoAboutVector(const Vector3D& v)
{
    cout << "X = " << v.getX() << endl;
    cout << "Y = " << v.getY() << endl;
    cout << "Z = " << v.getZ() << endl;
    cout << "isNull = " << (v.isNull() ? "True" : "False") << endl;
    cout << "length = " << v.length() << endl;
    cout << "normalized: ";
    v.normalized().print();
    cout << endl;
}

int main()
{
    Vector v(1, 2), v1(v);

    cout << "v: ";
    v.print();
    printInfoAboutVector(v);

    cout << "v1: ";
    v1.print();
    printInfoAboutVector(v1);

    cout << "Are they equal: " << (v.isEqual(v1) ? "Yes" : "No") << endl << endl;

    v.setX(3);
    v.setY(4);
    v.print();
    printInfoAboutVector(v);

    Vector v2 = v1;
    v2.print();
    printInfoAboutVector(v2);

    v2 = v;
    v2.print();
    printInfoAboutVector(v2);

    v.setVector(5, 6);
    v.print();
    printInfoAboutVector(v);

    v.multiplyByScalar(2);
    v.print();
    printInfoAboutVector(v);

    cout << "Is the two previous vector the one preceding it scaled by two: " << (areEqual(v, Vector(5, 6).multipliedByScalar(2)) ? "Yes" : "No") << endl << endl;
    cout << "Are they collinear: " << (v.isCollinear(Vector(5, 6)) ? "Yes" : "No") << endl << endl;

    Vector(9).print();
    printInfoAboutVector(Vector(9));

    Vector o = Vector();
    o.print();
    printInfoAboutVector(o);

    cout << "v normalized: "; v.normalized().print();
    cout << "v1 normalized: "; v1.normalized().print();
    cout << "Do v and v1 normalized form an orthonormal coordinate system: " << (v.normalized().isOrthonormalCoordinateSystem(v1.normalized()) ? "Yes" : "No") << endl << endl;

    cout << "Is the previous vector equal to the null vector: " << (o == Vector() ? "Yes" : "No") << endl << endl;

    Vector3D v3d(v1, 3);
    v3d.print();
    printInfoAboutVector(v3d);

    return 0;
}
