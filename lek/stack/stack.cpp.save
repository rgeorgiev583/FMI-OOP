#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{
    top=-1;
}

bool Stack::empty() const
{
    return top==-1;
}

bool Stack::full() const
{
    return top==MAX_STACK-1;
}

int Stack::size() const
{
    return top+1;
}

int Stack::peek() const
{
    if(empty())
        return 0;
    return a[top];
}

bool Stack::push(int x)
{
    if(full())
        return false;
    a[++top]=x;
    return true;
}

int Stack::pop()
{
    if(empty())
        return 0;
    return a[top--];
}
