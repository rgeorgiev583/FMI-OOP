#include <iostream>
#include "vector.h"
using namespace std;

Vector::Vector(int cap = 4)
{
    size = 0;
    capacity = cap;
    data = new int[cap];
}

void Vector::copy(const Vector& v)
{
    size = v.size;
    capacity = v.capacity;
    data = new int[v.capacity];
    for(int i=0;i<v.size;i++)
        data[i] = v.data[i];
}

void Vector::destroy()
{
    delete[] data;
}

void Vector::resize(int offset = 0,bool remove = false)
{
    if(size == capacity)
    {
        capacity *= 1.5;
        int* old_data = data;
        data = new int[capacity];
        for(int i=0;i<offset;i++)
            data[i] = old_data[i];
        for(int i=offset;i<size;i++)
            data[remove ? i : i+1] = old_data[remove ? i+1 : i];
        delete[] old_data;
    }
}

Vector::Vector(const Vector& v)
{
    copy(v);
}

Vector& Vector::operator=(const Vector& v)
{
    if(this != &v)
    {
        destroy();
        copy(v);
    }
    return *this;
}

Vector::~Vector()
{
    destroy();
}

void Vector::pushFront(int elem)
{
    resize(0);
    size++;
    data[0] = elem;
}

void Vector::pushBack(int elem)
{
    resize(size);
    data[size++] = elem;
}

void Vector::pushAt(int elem,int index)
{
    resize(index);
    size++;
    data[index] = elem;
}

int Vector::at(int index)
{
    return data[index];
}

int Vector::popFront()
{
    int elem = data[0];
    resize(0,true);
    size--;
    return elem;
}

int Vector::popBack()
{
    int elem = data[size - 1];
    resize(size-1,true);
    size--;
    return elem;
}
