#pragma once

class Animal
{
    size_t nLegs, color, type, weight;
    bool sex;

public:
    void eat();
    void breathe();
    void sleep();
    void poop();
};

class Cat: public Animal
{
    size_t lengthOfTail;

public:
    void eat();
    void meow();
};
