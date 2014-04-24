#include <iostream>
#include <cstring>
#include "dstring.h"

const int MAX_SIZE = (unsigned short) - 1;

void DynamicString::reallocate()
{
    char* newdata = new char[strlen(data) + 1];
    strcpy(newdata, data);
    delete[] data;
    data = newdata;
}

void DynamicString::reallocate(size_t capacity)
{
    char* newdata = new char[capacity];
    strcpy(newdata, data);
    delete[] data;
    data = newdata;
}

void DynamicString::copy(const DynamicString& ds)
{
    data = new char[strlen(ds.data) + 1];
    strcpy(data, ds.data);
}

void DynamicString::copy(const char* str)
{
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

void DynamicString::destroy()
{
    delete[] data;
}

DynamicString::DynamicString()
{
    data = new char[1];
    *data = 0;
}

DynamicString::DynamicString(const DynamicString& ds)
{
    copy(ds);
}

DynamicString::DynamicString(const char* str)
{
    copy(str);
}

DynamicString& DynamicString::operator=(const DynamicString& ds)
{
    if (this != &ds)
    {
        destroy();
        copy(ds);
    }

    return *this;
}

DynamicString& DynamicString::operator=(const char* str)
{
    if (data != str)
    {
        destroy();
        copy(str);
    }

    return *this;
}

DynamicString::~DynamicString()
{
    destroy();
}

bool DynamicString::empty() const
{
    return !(*data);
}

size_t DynamicString::size() const
{
    return strlen(data);
}

size_t DynamicString::find(const DynamicString& ds, size_t pos = 0) const
{
    char* found = strstr(data + pos, ds.data);
    return found ? (size_t) found - (size_t) data : -1;
}

char& DynamicString::at(size_t pos)
{
    return pos < size() ? data[pos] : data[size() - 1];
}

char& DynamicString::operator[](size_t pos)
{
    return at(pos);
}

std::ostream& operator<<(std::ostream& os, const DynamicString& ds)
{
    os << ds.data;
    return os;
}

std::istream& operator>>(std::istream& is, DynamicString& ds)
{
    ds.reallocate(MAX_SIZE);
    is >> ds.data;
    ds.reallocate();
    return is;
}

std::istream& getline(std::istream& is, DynamicString& ds)
{
    ds.reallocate(MAX_SIZE);
    is.getline(ds.data, MAX_SIZE);
    ds.reallocate();
    return is;
}
