#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
    Vector v;
    v.pushBack(2);
    v.pushFront(1);
    v.pushBack(4);
    v.pushAt(2, 3);
    cout << v.popBack() << endl << v.popBack() << endl << v.popBack() << endl << v.popBack() << endl;
    v.pushBack(1);
    v.pushBack(2);
    v.pushBack(3);
    cout << v.popFront() << endl << v.popFront() << endl << v.popFront() << endl;

	return 0;
}
