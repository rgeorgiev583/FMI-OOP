#pragma once

class WarMachine
{
protected:
    char* name;
    long damage;
    long totalDamage;
    Observer* obs;
public:
    WarMachine(char*, long = 500);
    WarMachine(const WarMachine&);
    WarMachine& operator=(const WarMachine&);
    ~WarMachine();
    virtual void fire() = 0;
    virtual void printStats();
};
