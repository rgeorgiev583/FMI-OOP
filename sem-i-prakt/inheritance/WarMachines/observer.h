#pragma once

class Observer
{
public:
    virtual void notify(const WarMachine*) = 0;
}

