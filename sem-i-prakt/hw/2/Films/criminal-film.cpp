#include "criminal-film.h"

CriminalFilm::CriminalFilm(): Film() {}

CriminalFilm::CriminalFilm(const char* _name, int _year = 0, int _victims = 0):
        Film(_name, _year), victims(_victims) {}

int CriminalFilm::getVictims() const
{
    return victims;
}

void CriminalFilm::setVictims(int _victims)
{
    victims = _victims;
}
