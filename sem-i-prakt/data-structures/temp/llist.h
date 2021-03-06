#include <cstddef>
#pragma once

struct Node
{
    Filter data;
    Node* next;

    Node(const Filter&, Node* = NULL);
};

class LinkedFilterList
{
    Node *front, *back;

    Node* base_splice(const LinkedFilterList&, Node*&);
    void copy(const LinkedFilterList&);
    void destroy();

public:
    LinkedFilterList();
    LinkedFilterList(const LinkedFilterList&);
    LinkedFilterList& operator=(const LinkedFilterList&);
    ~LinkedFilterList();

    size_t size();
    Filter& at(size_t);
    Filter& operator[](size_t);

    void push_front(const Filter&);
    void push_back(const Filter&);
    void push_at(const Filter&, size_t);
    bool pop_front();
    bool pop_back();
    bool pop_at(size_t);

    void splice(const LinkedFilterList&, size_t);
};
