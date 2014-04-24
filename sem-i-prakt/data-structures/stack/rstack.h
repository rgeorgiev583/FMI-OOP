#ifndef RSTACK_H_INCLUDED
#define RSTACK_H_INCLUDED
const int INIT_CAPACITY = 4;

class ResizingStack
{
    int* data;
    int size,capacity;
public:
    ResizingStack(int);
    ~ResizingStack();

    bool empty() const;
    int top() const;

    int pop();
    void push(int);
private:
    void resize();
};

#endif // RSTACK_H_INCLUDED
