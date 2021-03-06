#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MAX_STACK=100;

class Stack
{
    int a[MAX_STACK],top;
public:
    Stack();

    bool empty() const;
    bool full() const;
    int size() const;
    int peek() const;

    bool push(int);

    int pop();
};

#endif // STACK_H_INCLUDED
