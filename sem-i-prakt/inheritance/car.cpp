#include <iostream>
using namespace std;

void Car::drive(size_t km)
{
    millage += km;
}

void Car::printInfo()
{
    cout << "Power: " << power << " hp" << endl;
    cout << "Color: " << color << endl;
    cout << "Millage: " << millage << " km" << endl;
    cout << "Fuel: " << fuel << " l" << endl;
    cout << "Is transmission automatic: " << (automaticGearBox ? "Yes" : "No") << endl;
}

void

int main()
{


	return 0;
}
