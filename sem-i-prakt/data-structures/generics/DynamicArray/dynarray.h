#pragma once

template<typename T>
class DynamicArray
{
    size_t size, capacity;
    T* data;

    void reallocate();
    void reallocate(size_t);
    void copy(const DynamicArray&);
    void copy(const T*, size_t);
    void destroy();

public:
    DynamicArray();
    DynamicArray(const DynamicArray&);
    DynamicArray(const T*, size_t);
	DynamicArray& operator=(const DynamicArray&);
    DynamicArray& operator=(const T*, size_t);
	~DynamicArray();

	bool empty() const;
    size_t size() const;

    T& at(size_t);
    T& operator[](size_t);

    DynamicArray& operator+=(const DynamicArray&);

    friend DynamicArray operator+(const DynamicArray&, const DynamicArray&);
    friend bool operator==(const DynamicArray&, const DynamicArray&);
    friend bool operator<(const DynamicArray&, const DynamicArray&);
};
