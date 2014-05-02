#include <iostream>
#include "llist.cpp"
using namespace std;

int main()
{
    LinkedList<int> l;

    for (size_t i = 0; i < 10; i++)
        l.push_back(i);

    for (LinkedListIterator<int> i = l.begin(); i != l.end(); i++)
        cout << *i << endl;

	return 0;
}
