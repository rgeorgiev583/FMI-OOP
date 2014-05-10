#include <cstddef>
#pragma once

template<typename T>
class DynamicArray
{
    T* data;
    size_t length, capacity;

    void reallocate(size_t);
    void reallocate();
    void shrink();
    void copy(const DynamicArray<T>&);
    void copy(const T*, size_t);
    void destroy();

public:
    DynamicArray();
    DynamicArray(size_t);
    DynamicArray(const DynamicArray<T>&);
    DynamicArray(const T*, size_t);
	DynamicArray<T>& operator=(const DynamicArray<T>&);
	~DynamicArray();

	bool empty() const;
    size_t size() const;

    T& front();
    T& back();
    T& at(size_t);
    T& operator[](size_t);

    void push_back(const T&);
    bool pop_back();

    void swap(DynamicArray<T>&);
    void clear();
};
