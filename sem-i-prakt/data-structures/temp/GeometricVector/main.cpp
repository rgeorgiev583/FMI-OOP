#include <iostream>
#include "vector.h"
#include "vector3d.h"

using namespace std;

int main()
{
    Vector v(1,2);
    Vector3D v3d(3,4,5);
    v.print();
    v3d.print();

    return 0;
}
