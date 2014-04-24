#include <cstddef>
#pragma once

template<typename T> struct Node
{
    T data;
    Node* next;

    Node(const T&, Node* = NULL);
};

template<typename T> class LinkedList
{
    Node<T> *frontnode, *backnode;

    void copy(const LinkedList<T>&);
    void destroy();
    T* base_at(size_t);
    Node<T>* base_splice(const LinkedList<T>&, Node<T>*&);
    void base_reverse(Node<T>*);

public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList& operator=(const LinkedList<T>&);
    ~LinkedList();

    bool empty() const;
    size_t size() const;

    T& front();
    T& back();
    T& at(size_t);
    T& operator[](size_t);
    void push_front(const T&);
    void push_back(const T&);
    void push_at(const T&, size_t);
    bool pop_front();
    bool pop_back();
    bool pop_at(size_t);

    void splice(const LinkedList<T>&, size_t);
    void reverse();
};
