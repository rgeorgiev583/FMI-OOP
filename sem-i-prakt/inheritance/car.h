#pragma once

const int SIZE = 10;

class Car
{
    size_t power, year, millage;
    char color[SIZE];
    size_t fuel;
    bool automaticGearBox;

public:
    void drive(size_t);
    void load(size_t);
};

class Ford: public Car
{
    char make[SIZE];

public:
};

class Focus: public Ford
{
    char model[SIZE];

public:

};
