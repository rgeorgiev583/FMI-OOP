#include <iostream>
#include "rstack.h"
using namespace std;

ResizingStack::ResizingStack(int capacity = INIT_CAPACITY)
{
    this->capacity = capacity;
    this->size = 0;
    this->data = new int[capacity];
}

ResizingStack::~ResizingStack()
{
    delete[] data;
}

bool ResizingStack::empty() const
{
    return !size;
}

int ResizingStack::top() const
{
    if(size > 0)
        return data[size-1];
    else
        return 0;
}

int ResizingStack::pop()
{
    if(size > 0)
        return data[size--];
    else
        return 0;
}

ResizingStack::push(int elem)
{
    if(size < capacity)
        resize();

    data[size] = elem;
}

void ResizingStack::resize()
{
    capacity *= 2;
    int* tmp = data;
    data = new int[capacity];
    for(int i=0;i<size;i++)
        data[i] = tmp[i];
    delete[] tmp;
}

int main()
{
    ResizingStack s;

	return 0;
}
