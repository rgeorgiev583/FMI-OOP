#include <iostream>
using namespace std;
const int INIT = 4;

void reallocate(size_t newcapacity)
{
    if (newcapacity >= size)
    {
        T* olddata = data;
        data = new T[newcapacity];

        for(size_t i = 0; i < da.size; i++)
            data[i] = olddata[i];

        delete[] olddata;
    }
}

void DynamicArray::copy(const DynamicArray& da)
{
    capacity = size = da.size;
    data = new T[da.size];

    for(size_t i = 0; i < da.size; i++)
        data[i] = da.data[i];
}

void destroy()
{
    delete[] data;
}

DynamicArray::DynamicArray(): size(0), capacity(INIT)
{
    data = new T[INIT];
}

DynamicArray::DynamicArray(const T* arr, size_t arrlen)
{
    capacity = size = arrlen;
    arr = new T[arrlen];

    for(size_t i = 0; i < arrlen; i++)
        data[i] = arr[i];
}

DynamicArray::DynamicArray(const DynamicArray& da)
{
    copy(da);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& da)
{
    if (this != &da)
    {
        destroy();
        copy(da);
    }

    return *this;
}

DynamicArray::~DynamicArray()
{
    destroy();
}

T& DynamicArray::operator[](size_t pos)
{
    return data[pos];
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& da)
{
    size_t max

    reallocate(da.capacity)
}
