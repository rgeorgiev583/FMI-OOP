#include <iostream>
#include "point2d.cpp"
using namespace std;

int main()
{
	Point2D p(1,2);
	p.translate(Point2D(3,5));
	p.print();cout<<endl;
    cout<<p.distance()<<endl;
    Point2D q=p;
    q.translate(Point2D(-3,4));
    cout<<p.distance(q)<<endl;

	return 0;
}
