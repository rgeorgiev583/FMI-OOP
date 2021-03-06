#include <cstddef>
#pragma once

struct Node
{
    int data;
    Node* next;

    Node(int = 0, Node* = NULL);
};

class LinkedList
{
    Node *front, *back;

    Node* base_splice(const LinkedList&, Node*&);
    void copy(const LinkedList&);
    void destroy();

public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();

    size_t size() const;
    int at(size_t);
    int operator[](size_t);

    void push_front(int);
    void push_back(int);
    void push_at(int, size_t);
    bool pop_front();
    bool pop_back();
    bool pop_at(size_t);

    void splice(const LinkedList&, size_t);
};
