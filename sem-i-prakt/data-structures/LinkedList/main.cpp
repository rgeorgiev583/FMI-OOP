#include <iostream>
#include "llist.h"
using namespace std;
typedef LinkedList List;

int main()
{
	List l;

	for(int i = 0; i < 10; i++)
        l.push_back(i);

    List l1(l);

    for(int i = 0; i < 10; i++)
        cout << l1[i] << endl;
l1[0]='a';
    return 0;
}
