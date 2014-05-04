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

    void copy(size_t, const T&);
    void copy(const T*, size_t);
    void copy(const LinkedListIterator<T>&, const LinkedListIterator<T>&);
    void copy(const LinkedList<T>&);
    void destroy();
    T* base_at(size_t);
    void
    void pop_after(const LinkedListIterator<T>&);
    Node<T>* base_splice(const LinkedList<T>&, Node<T>*&);
    Node<T>* base_splice(const T*, size_t, Node<T>*&);
    void base_reverse(Node<T>*);

public:
    LinkedList();
    LinkedList(size_t, const T&);
    LinkedList(const T*, size_t);
    LinkedList(LinkedListIterator<T>, LinkedListIterator<T>);
    LinkedList(const LinkedList<T>&);
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

    void assign(size_t, const T&);
    void assign(const T*, size_t);
    void assign(LinkedListIterator<T>, LinkedListIterator<T>);
    void push_front(const T&);
    void push_back(const T&);
    void push_at(size_t, const T&);
    bool pop_front();
    bool pop_back();
    bool pop_at(size_t);
    LinkedListIterator<T> insert(LinkedListIterator<T>, const T&);
    void insert(LinkedListIterator<T>, size_t, const T&);
    void insert(LinkedListIterator<T>, LinkedListIterator<T>, LinkedListIterator<T>);
    LinkedListIterator<T> erase(LinkedListIterator<T>);
    LinkedListIterator<T> erase(LinkedListIterator<T>, LinkedListIterator<T>);

    void swap(const LinkedList<T>&);
    void clear();
    void splice(const LinkedList<T>&, size_t);
    void reverse();
};
