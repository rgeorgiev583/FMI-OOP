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

    cout << "v: "; v.print();
    cout << "v1: "; v1.print();
    cout << "Do v and v1 normalized form an orthonormal coordinate system: " << (v.normalized().isOrthonormalCoordinateSystem(v1.normalized()) ? "Yes" : "No") << endl << endl;
    cout << "Do (1, 0) and (0, 1) form an OCS: " << (Vector(0, 1).isOrthonormalCoordinateSystem(Vector(1, 0)) ? "Yes" : "No") << endl << endl;
    cout << "Do (1, 0) and (0, 1) form an OCS: " << (isOrthonormalCoordinateSystem(Vector(0, 1), Vector(1, 0)) ? "Yes" : "No") << endl << endl;
    cout << "Sum of v and v1: "; v.sum(v1).print();
    cout << "Should be 'Yes': " << (v.sum(v1) == v + v1 ? "Yes" : "No") << endl;
    v.add(v1);
    cout << "v: "; v.print();
    cout << "Difference of v and v1: "; v.difference(v1).print();
    v.subtract(v1);
    cout << "v: "; v.print();
    cout << "Scalar product of v and v1: " << v.scalarProduct(v1) << endl;
    cout << "Scalar product of (0, 1) and (1, 0): " << Vector(0, 1).scalarProduct(Vector(1, 0)) << endl;
    v2.read();
    (v2 += v1).print();
    (v -= v2).print();
    (v2 *= 3).print();
    (v * 5).print();
    (v + v2).print();
    (v - v2).print();
    cout << scalarProduct(v1, v2) << endl;
    cout << "Is the previous vector equal to the null vector: " << (o == Vector() ? "Yes" : "No") << endl << endl;

    cout << endl << endl << endl << "------ Now let's test 3D vectors! ------" << endl << endl << endl;

    Vector3D v3d(v1, 3);
    v3d.print();
    printInfoAboutVector(v3d);

    v3d.read();
    v3d.print();
    v3d = Vector3D(1, 2, 3);
    Vector3D v13d(v3d);

    cout << "v3d: ";
    v3d.print();
    printInfoAboutVector(v3d);

    cout << "v13d: ";
    v13d.print();
    printInfoAboutVector(v13d);

    cout << "Are they equal: " << (v3d.isEqual(v13d) ? "Yes" : "No") << endl << endl;

    v3d.setX(3);
    v3d.setY(4);
    v3d.setZ(5);
    v3d.print();
    printInfoAboutVector(v3d);

    Vector3D v23d = v13d;
    v23d.print();
    printInfoAboutVector(v23d);

    v23d = v3d;
    v23d.print();
    printInfoAboutVector(v23d);

    v3d.setVector(Vector(5, 7), 6);
    v3d.print();
    printInfoAboutVector(v3d);

    v3d.multiplyByScalar(2);
    v3d.print();
    printInfoAboutVector(v3d);

    cout << "Is the two previous vector the one preceding it scaled by two: " << (areEqual(v3d, Vector3D(5, 6).multipliedByScalar(2)) ? "Yes" : "No") << endl << endl;
    cout << "Are they collinear: " << (v3d.isCollinear(Vector3D(5, 6)) ? "Yes" : "No") << endl << endl;

    Vector3D(9).print();
    printInfoAboutVector(Vector3D(9));

    Vector3D o3d = Vector3D();
    o3d.print();
    printInfoAboutVector(o3d);

    cout << "v3d: "; v3d.print();
    cout << "v13d: "; v13d.print();
    cout << "Do v3d, v13d and v23d normalized form an orthonormal coordinate system: " << (v3d.normalized().isOrthonormalCoordinateSystem(v13d.normalized(), v23d.normalized()) ? "Yes" : "No") << endl << endl;
    cout << "Do (1, 0, 0), (0, 1, 0) and (0, 0, 1) form an OCS: " << (isOrthonormalCoordinateSystem(Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1)) ? "Yes" : "No") << endl << endl;
    cout << "Do (1, 0, 0), (0, 1, 0) and (0, 0, 1) form an OCS: " << (Vector3D(1, 0, 0).isOrthonormalCoordinateSystem(Vector3D(0, 1, 0), Vector3D(0, 0, 1)) ? "Yes" : "No") << endl << endl;
    cout << "Sum of v3d and v13d: "; v3d.sum(v13d).print();
    cout << "Should be 'Yes': " << (v3d.sum(v13d) == v3d + v13d ? "Yes" : "No") << endl;
    v3d.add(v13d);
    cout << "v3d: "; v3d.print();
    cout << "Difference of v3d and v13d: "; v3d.difference(v13d).print();
    v3d.subtract(v13d);
    cout << "v3d: "; v3d.print();
    cout << "Scalar product of v3d and v13d: " << v3d.scalarProduct(v13d) << endl;
    cout << "Scalar product of (0, 1) and (1, 0): " << Vector3D(0, 1).scalarProduct(Vector3D(1, 0)) << endl;
    v23d.read();
    (v23d += v13d).print();
    (v3d -= v23d).print();
    (v23d *= 3).print();
    (v3d * 5).print();
    (v3d + v23d).print();
    (v3d - v23d).print();
    cout << scalarProduct(v13d, v23d) << endl;
    cout << "Is the previous vector equal to the null vector: " << (o3d == Vector3D() ? "Yes" : "No") << endl << endl;


    return 0;
}
