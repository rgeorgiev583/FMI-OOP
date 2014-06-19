#include <iostream>
#include "army.h"

Army::Army()
{
    machines = new Machine*[500];
}

void Army::addMachine(WarMachine* m)
{
    *machines[++machineCount] = *m;
}

void Army::fire()
{
    for (size_t i=0; i<machineCount;i++)
        machines[i]->fire();
}

void Army::notify(WarMachine* m)
{
    std::cout << m->name << " has fired!" << std::endl;
}
