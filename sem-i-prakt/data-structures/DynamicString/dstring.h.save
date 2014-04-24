#include <iostream>
#pragma once

class DynamicString
{
    char* data;

    void reallocate();
    void reallocate(size_t);
    void copy(const DynamicString&);
    void copy(const char*);
    void destroy();

public:
    static const size_t npos = (size_t) - 1;

    DynamicString();
    DynamicString(const DynamicString&);
    DynamicString(const char*);
	DynamicString& operator=(const DynamicString&);
    DynamicString& operator=(const char*);
	~DynamicString();

	bool empty() const;
    size_t size() const;
    size_t find(const DynamicString&, size_t = 0) const;

    char& at(size_t);
    char& operator[](size_t);

    friend std::ostream& operator<<(std::ostream&, const DynamicString&);
    friend std::istream& operator>>(std::istream&, DynamicString&);
    friend std::istream& getline(std::istream&, DynamicString&);
};
