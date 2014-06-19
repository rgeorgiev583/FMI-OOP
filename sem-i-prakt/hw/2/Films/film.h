#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include "ifilm.h"

class Film: public IFilm
{
    char* name;
    int year;

    void copy(const Film&);
    void destroy();
public:
    Film();
    Film(const char*, int = 0);
    Film(const Film&);
    Film& operator=(const Film&);
    ~Film();

    const char* getName() const;
    int getShootingYear() const;

    void setName(const char*);
    void setShootingYear(int);
};

#endif // FILM_H_INCLUDED
