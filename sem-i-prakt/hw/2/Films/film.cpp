#include "film.h"

#include <cstring>

void Film::copy(const Film& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void Film::destroy()
{
    delete[] name;
}

Film::Film(): name(NULL) {}

Film::Film(const char* _name, int _year = 0): name(NULL), year(_year)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

Film::Film(const Film& other)
{
    copy(other);
}

Film& Film::operator=(const Film& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

Film::~Film()
{
    destroy();
}

const char* Film::getName() const
{
    return name;
}

int Film::getShootingYear() const
{
    return year;
}

void Film::setName(const char* _name)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

void Film::setShootingYear(int _year)
{
    year = _year;
}
