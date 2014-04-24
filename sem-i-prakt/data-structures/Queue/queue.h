#include <cstddef>
#pragma once
const int DEFAULT = 0;

struct Node
{
    int data;
    Node* next;

    Node(int = DEFAULT, Node* = NULL);
};

class Queue
{
    Node *frontnode, *backnode;

    void copy(const Queue&);
    void destroy();

public:
    Queue();
    Queue(const Queue&);
    Queue& operator=(const Queue&);
    ~Queue();

    bool empty() const;
    int front() const;

    void push(int);
    bool pop();
};
