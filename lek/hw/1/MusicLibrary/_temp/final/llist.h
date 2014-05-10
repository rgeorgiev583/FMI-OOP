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

    Node<T>* node_at(size_t);

public:
    LinkedListIterator(const Node<T>* = NULL);

    operator Node<T>*();
    operator T*();

    T& operator*();
    T* operator->();
    T& operator[](size_t);

    bool operator==(const LinkedListIterator<T>&) const;
    bool operator!=(const LinkedListIterator<T>&) const;

    LinkedListIterator<T> operator+(size_t) const;
    LinkedListIterator<T>& operator+=(size_t);
    LinkedListIterator<T>& operator++();
    LinkedListIterator<T> operator++(int);
};

template <typename T>
class LinkedList
{
    Node<T> *frontnode, *backnode;

    void copy(size_t, const T&);
    void copy(const T*, size_t);
    void copy(const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    void copy(const LinkedList<T>&);
    void destroy();
    void base_reverse(Node<T>*);

public:
    LinkedList();
    LinkedList(size_t, const T&);
    LinkedList(const T*, size_t);
    LinkedList(const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    LinkedList(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    ~LinkedList();

    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();

    bool empty() const;
    size_t size() const;

    T& front();
    T& back();

    void assign(size_t, const T&);
    void assign(const T*, size_t);
    void assign(const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    void push_front(const T&);
    void push_back(const T&);
    bool pop_front();
    bool pop_back();
    LinkedListIterator<T> insert(const LinkedListIterator<T>&, const T&);
    void insert(const LinkedListIterator<T>&, size_t, const T&);
    void insert(const LinkedListIterator<T>&, const T*, size_t);
    void insert(const LinkedListIterator<T>&, const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    LinkedListIterator<T> erase(const LinkedListIterator<T>&);
    LinkedListIterator<T> erase(const LinkedListIterator<T>&, const LinkedListIterator<T>&);

    void swap(const LinkedList<T>&);
    void clear();
    void splice(const LinkedListIterator<T>&, LinkedList<T>&);
    void splice(const LinkedListIterator<T>&, LinkedList<T>&, const LinkedListIterator<T>&);
    void splice(const LinkedListIterator<T>&, LinkedList<T>&, const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    void reverse();
};
