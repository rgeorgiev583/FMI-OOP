#include <cstring>
#pragma once

struct Node
{
    char* data;
    Node* next;

    Node(): data(NULL), next(NULL) {}

    Node(const char* s): next(NULL)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    Node(const char* s, Node* _next): next(_next)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    ~Node()
    {
        delete[] data;
    }
};

class Stack
{
    Node* top;

    void copy(const Stack&);
    void destroy();
public:
    Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();
    bool empty() const;
    char* peek() const;
    void push(const char*);
    bool pop();
};
