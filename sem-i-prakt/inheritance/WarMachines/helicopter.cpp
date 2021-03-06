#include <iostream>
#include "helicopter.h"

Helicopter::Helicopter(char* _name, long _damage, long _maxAlt): WarMachine(_name, _damage), maxAlt(_maxAlt) {}

void Helicopter::fire()
{
    totalDamage += maxAlt * damage;
}

void Helicopter::printStats()
{
    std::cout << "Max altitude: " << maxAlt << endl;
}
