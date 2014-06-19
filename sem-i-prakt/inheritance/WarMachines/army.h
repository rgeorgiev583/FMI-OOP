#include "warmachine.h"
#include "observer.h"

class Army: public Observer
{
    WarMachine** machines;
    size_t machineCount;

public:
    Army();
    void addMachine(WarMachine*);
    void fire();
    void notify(WarMachine*);
};
