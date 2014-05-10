#pragma once

template<typename T>
class DynamicArray
{
    size_t size, capacity;
    T* data;

    void copy(const DynamicArray&);
    void destroy();
    void reallocate(size_t);
public:
    DynamicArray();
    DynamicArray(const T*, size_t);
    DynamicArray(const DynamicArray&);
    DynamicArray& operator=(const DynamicArray&);
    ~DynamicArray();

    T& operator[](size_t);

    DynamicArray& operator+=(const DynamicArray&);

    friend bool operator==(const DynamicArray&, const DynamicArray&);
    friend bool operator<(const DynamicArray&, const DynamicArray&);
    friend DynamicArray operator+(const DynamicArray&, const DynamicArray&);
}
