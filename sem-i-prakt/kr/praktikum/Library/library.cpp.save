#include "library.h"

Library::Library(): books(NULL) {}

void Library::resize()
{
    if (capacity >= length)
    {
        char* rsbooks = new Book[length];

        for (size_t i = 0; i < length; i++)
            rsbooks[i] = books[i];

        books = rsbooks;
    }
}

void Library::copy(const Library& other)
{
    books = new Book[other.capacity];

    for (size_t i = 0; i < length; i++)
    {
        books[i].name = other.books[i].name;
        books[i].pageCount = other.books[i].pageCount;
    }
}

void Library::destroy()
{
    delete[] books;
}

Library::Library(const Library& other): books(NULL), length(other.length),
        capacity(other.capacity)
{
    copy(other);
}

Library& Library::operator=(const Library&)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Library::~Library()
{
    destroy();
}

Book& Library::operator[](size_t pos)
{
    return books[pos];
}

void Library::appendBook(const Book& b)
{
    books[length].name = b.name;
    books[length].pageCount = b.pageCount;
    length++;
}

void Library::removeBook(size_t pos)
{
    for (size_t i = pos; i < length; i++)
    {
        books[i].name = books[i+1].name;
        books[i].pageCount = books[i+1].pageCount;
    }
    length--;
}

size_t Library::meanPagesOfBooks() const
{
    size_t mean = 0;

    for (size_t i = pos; i < length; i++)
    {
        mean += books[i].pageCount;
    }

    return mean/length;
}

void Library::sortByTitle(const char* title)
{


    for (size_t i=0;i<length-1;i++)
    {
        size_t maxi = 0;

        for(size_t j=i+1;j<n;j++)
        {
            if(strcmp(books[i].name,books[j]))
        }
    }
}
