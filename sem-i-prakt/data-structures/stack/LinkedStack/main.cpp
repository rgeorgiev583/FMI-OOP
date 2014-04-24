#include <iostream>
#include "lstack.h"
using namespace std;

int main()
{
    char* str;
    Stack s;
    s.push("asd");
    str = s.peek();
    cout<<"\""<<str<<"\""<<endl;
    Stack s1(s);
    s1.push("");
    cout<<"\""<<s1.peek()<<"\""<<endl;
    Stack s2;
    s2 = s1;
    s1.pop();
    cout<<"\""<<s1.peek()<<"\""<<endl;
    s1.pop();
    cout<<"\""<<s2.peek()<<"\""<<endl;
    s2.pop();
    cout<<"\""<<s2.peek()<<"\""<<endl;
    s2.pop();
    if(s1.empty())
        cout<<"s1 е празен!"<<endl;
    if(s2.empty())
        cout<<"s2 е празен!"<<endl;

	return 0;
}
