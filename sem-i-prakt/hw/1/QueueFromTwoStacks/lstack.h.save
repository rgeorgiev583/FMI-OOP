#include <cstddef>
#pragma once
const int DEFAULT = 0;

struct Node
{
    int data;
    Node* next;

    Node(int = DEFAULT, Node* = NULL);
};

class LinkedStack
{
    Node* topnode;

    void copy(const LinkedStack&);
    void destroy();

public:
    LinkedStack();
    LinkedStack(const LinkedStack&);
    LinkedStack& operator=(const LinkedStack&);
    ~LinkedStack();

    bool empty() const;
    int top() const;

    void push(int);
    bool pop();
};
