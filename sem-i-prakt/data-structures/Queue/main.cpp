#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	Queue q;

	for(int i = 0; i < 10; i++)
        q.push(i);

    /*while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }*/

    Queue q1(q);

    while (!q1.empty())
    {
        cout << q1.front() << endl;
        q1.pop();
    }

	return 0;
}
