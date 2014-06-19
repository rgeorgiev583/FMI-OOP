#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double getArea() {return 0;}
    double getPerimeter() {return 0;}
};

class Triangle: public Shape
{
    double a, b, c;

public:
    Triangle(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
    double getPerimeter() {return a + b + c;}
    double getArea() {double p = getPerimeter() / 2; return sqrt(p * (p - a) * (p - b) * (p - c));}
};

int main()
{
    Triangle t(3, 4, 5);
    Shape* ptr = &t;
    cout << "Perimeter: " << ptr->getPerimeter() << endl;
    cout << "Area: " << ptr->getArea() << endl;

	return 0;
}
