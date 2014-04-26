#include "dynarray.h"
#pragma once
const size_t INIT = 4;

template<typename T>
void DynamicArray<T>::reallocate()
{
    T* olddata = data;
    data = new T[length];

    for (size_t i = 0; i < length; i++)
        data[i] = olddata[i];

    delete[] olddata;
    capacity = length;
}

template<typename T>
void DynamicArray<T>::reallocate(size_t _capacity)
{
    T* olddata = data;
    data = new T[_capacity];

    for (size_t i = 0; i < length; i++)
        data[i] = olddata[i];

    delete[] olddata;
    capacity = _capacity;
}

template<typename T>
void DynamicArray<T>::copy(const DynamicArray<T>& other)
{
    data = new T[other.capacity];

    for (size_t i = 0; i < other.length; i++)
        data[i] = other.data[i];

    length = other.length;
    capacity = other.capacity;
}

template<typename T>
void DynamicArray<T>::copy(const T* arr, size_t arrlen)
{
    data = new T[arrlen];

    for (size_t i = 0; i < arrlen; i++)
        data[i] = arr[i];

    capacity = length = arrlen;
}

template<typename T>
void DynamicArray<T>::destroy()
{
    delete[] data;
}

template<typename T>
DynamicArray<T>::DynamicArray(): length(0), capacity(INIT)
{
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t _capacity): length(0), capacity(_capacity)
{
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
    copy(other);
}

template<typename T>
DynamicArray<T>::DynamicArray(const T* arr, size_t arrlen)
{
    copy(arr, arrlen);
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    destroy();
}

template<typename T>
bool DynamicArray<T>::empty() const
{
    return !length;
}

template<typename T>
size_t DynamicArray<T>::size() const
{
    return length;
}

template<typename T>
T& DynamicArray<T>::at(size_t pos)
{
    return data[pos];
}

template<typename T>
T& DynamicArray<T>::operator[](size_t pos)
{
    return at(pos);
}
