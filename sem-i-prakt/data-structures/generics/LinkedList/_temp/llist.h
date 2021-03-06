#include <cstddef>
#pragma once

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T&, Node<T>* = NULL);
};

template <typename T>
class LinkedListIterator
{
    Node<T>* node;

    Node<T>* node_at(size_t) const;

public:
    LinkedListIterator(const Node<T>* = NULL);

    operator Node<T>*();
    operator T*();

    T& operator*();
    T& operator[](size_t);

    bool operator==(const LinkedListIterator<T>&) const;
    bool operator!=(const LinkedListIterator<T>&) const;

    LinkedListIterator<T> operator+(size_t) const;
    LinkedListIterator<T>& operator+=(size_t);
    LinkedListIterator<T>& operator++();
    LinkedListIterator<T>& operator++(int);
};

template <typename T>
class LinkedList
{
    Node<T> *frontnode, *backnode;

    void copy(const LinkedList<T>&);
    void copy(const T*, size_t);
    void destroy();
    T* base_at(size_t);
    Node<T>* base_splice(const LinkedList<T>&, Node<T>*&);
    Node<T>* base_splice(const T*, size_t, Node<T>*&);
    void base_reverse(Node<T>*);

public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList(const T*, size_t);
    LinkedList<T>& operator=(const LinkedList<T>&);
    ~LinkedList();

    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();

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
