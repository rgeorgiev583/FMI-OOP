#include "warmachine.h"

WarMachine::WarMachine(char* _name, double _damage = 500): damage(_damage)
{
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

WarMachine::WarMachine(const WarMachine& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    damage = other.damage;
}

WarMachine::~WarMachine()
{
    delete[] name;
}

void WarMachine::fire()
{
    std::cout << "Name: " << name << endl;
    std::cout << "Damage: " << damage << endl;
    std::cout << "Total damage: " << totalDamage << endl;
}
