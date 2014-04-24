#include <iostream>
#include "llist.cpp"
using namespace std;

int main()
{
    LinkedList<int> l;

    for(int i=0;i<10;i++)
        l.push_back(i);

    for(int i=0;i<10;i++)
        cout<<l[i]<<endl;

	return 0;
}
