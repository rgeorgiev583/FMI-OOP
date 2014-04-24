#include <iostream>
#include "stack.cpp"
using namespace std;

bool do_braces_match()
{
    Stack s;
    char c;
    do
    {
        cin>>c;
        switch(c)
        {
        case '(':
        case '[':
        case '{':
            s.push(c);
            break;
        case ')':
            if(s.empty()||s.pop()!='(')
                return false;
            break;
        case ']':
            if(s.empty()||s.pop()!='[')
                return false;
            break;
        case '}':
            if(s.empty()||s.pop()!='{')
                return false;
        }
    }
    while(c!='.');
    return s.empty();
}

int main()
{
    cout<<(do_braces_match()?"OK!":"Fail!")<<endl;

	return 0;
}
