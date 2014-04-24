#include <iostream>
#include "stack.cpp"
using namespace std;

int main()
{
	Stack s;
	for(int i=1;i<=10;i++)
        s.push(i);
    while(!s.empty())
    {
        cout<<s.pop()<<endl;
    }

	return 0;
}
