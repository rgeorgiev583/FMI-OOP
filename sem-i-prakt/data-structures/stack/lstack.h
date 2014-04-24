#ifndef LSTACK_H_INCLUDED
#define LSTACK_H_INCLUDED

class LinkedStack
{
    int data;
    LinkedStack* last;
public:
    LinkedStack(int);
    ~LinkedStack();

    bool empty() const;
    int top() const;

    int pop();
    void push(int);
private:
    void resize();
};

#endif // LSTACK_H_INCLUDED
