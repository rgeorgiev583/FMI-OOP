#ifndef CRIMINAL-FILM_H_INCLUDED
#define CRIMINAL-FILM_H_INCLUDED

#include "film.h"

class CriminalFilm: public Film
{
    int victims;

public:
    CriminalFilm();
    CriminalFilm(const char*, int = 0, int = 0);

    int getVictims() const;

    void setVictims(int);
};

#endif // CRIMINAL-FILM_H_INCLUDED
