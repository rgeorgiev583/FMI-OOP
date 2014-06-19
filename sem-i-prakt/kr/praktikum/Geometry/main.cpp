#include <iostream>
#include "body.h"
#include "prism.h"
#include "cylinder.h"
using namespace std;
const size_t MAX_SIZE = 1000;

int main()
{
    StraightBody* sb[MAX_SIZE];
    cout << "Enter number of bodies: "; size_t n; cin >> n;
    if (!cin)
    {
        cerr << "ERROR: Invalid number of bodies!" << endl;
        return 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        bool b;
        cout << "Enter body type (0 for prism, 1 for cylinder):";
        sb[i] = b ? (StraightBody*) new StraightDiamondPrism() : (StraightBody*) new StraightCircularCylinder();
        cin >> *sb[i];
    }

    double meanTotalSurfaceArea = 0;

    for (size_t i = 0; i < n; i++)
        meanTotalSurfaceArea += sb[i]->getTotalSurfaceArea();

    meanTotalSurfaceArea /= n;

    double sumVolumes = 0;

    for (size_t i = 0; i < n; i++)
        if (sb[i]->getTotalSurfaceArea() > meanTotalSurfaceArea)
            sumVolumes += sb[i]->getVolume();

    cout << sumVolumes << endl;

	return 0;
}
