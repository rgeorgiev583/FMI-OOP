#pragma once

class Vector
{
    int* data;
    int size, capacity;
public:
    Vector(int);
private:
    void copy(const Vector&);
    void destroy();
    void resize(int,bool);
public:
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    ~Vector();
    void pushFront(int);
    void pushBack(int);
    void pushAt(int,int);
    int at(int);
    int popFront();
    int popBack();
};
