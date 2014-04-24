#include <iostream>
#include "tsqueue.h"

using namespace std;
typedef TwoStackQueue Queue;

// Тест на опашката
int main()
{
	Queue q;

	for (int i = 0; i < 10; i++)
        q.push(i);

    Queue q1(q), q2;
    q2 = q1;

    while (!q.empty())
        q.pop();

    cout << q.front() << endl;
    cout << q.empty() << endl;
    cout << q.pop() << endl;
    q.push(10);
    cout << q.front() << endl;
    cout << q.empty() << endl;
    cout << q.pop() << endl;

    while (!q2.empty())
    {
        cout << q2.front() << endl;
        q2.pop();
    }

    return 0;
}
