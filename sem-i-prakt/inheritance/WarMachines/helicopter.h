#include "warmachine.h"

class Helicopter: public WarMachine
{
    double maxAlt;

public:
    Helicopter(char*, long, long);
    void fire();
    void printStats();
}
