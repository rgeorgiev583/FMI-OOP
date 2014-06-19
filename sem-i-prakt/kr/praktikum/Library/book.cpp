#include <cstring>

#include "book.h"

void Book::resize(size_t newsize)
{
    char* rsname = new char[newsize];
    strcpy(rsname, name);
    delete[] name;
    name = rsname;
}

void Book::resize()
{
    char* rsname = new char[strlen(name) + 1];
    strcpy(rsname, name);
    delete[] name;
    name = rsname;
}

void Book::copy(const Book&)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Book::destroy()
{
    delete[] name;
}

Book::Book(): name(NULL), pageCount(0) {}

Book::Book(const char* _name, size_t _pageCount):
        name(NULL), pageCount(_pageCount)
{
    setName(_name);
}

Book::Book(const Book& other): name(NULL), pageCount(other.pageCount)
{
    copy(other);
}

Book& operator=(const Book& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Book::~Book()
{
    destroy();
}

const char* Book::getName() const
{
    return name;
}

size_t Book::getPageCount() const
{
    return pageCount;
}

void Book::setName(const char* _name)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Book::setPageCount(size_t _pageCount)
{
    pageCount = _pageCount;
}

bool operator<(const Book& b1, const Book& b2) const
{
    return stcmp(b1.name, b2.name) == -1;
}

bool operator>(const Book& b1, const Book& b2) const
{
    return stcmp(b1.name, b2.name) == 1;
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
    os << "== Book ==" << std::endl;
    os << "Name: " << name << std::endl;
    os << "Page count: " << pageCount << std::endl;
    return os;
}

std::istream& operator>>(std::istream&, Book& b)
{
    b.resize(MAX_SIZE);
    is.getline(b.name, MAX_SIZE);
    b.resize();
    is >> pageCount;
    return is;
}
