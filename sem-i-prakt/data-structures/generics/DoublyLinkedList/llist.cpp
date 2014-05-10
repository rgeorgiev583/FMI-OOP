#include <cstddef>
//<DEBUG>
#include <iostream>
//</DEBUG>
#include "llist.h"
#pragma once

template <typename T>
Node<T>::Node(const T& _data, Node<T>* _prev = NULL, Node<T>* _next = NULL): data(_data), prev(_prev), next(_next) {}

template <typename T>
Node<T>* LinkedListIterator<T>::node_at(size_t pos)
{
    size_t i = 0;
    Node<T>* curnode;

    if (pos >= 0)
        for (curnode = node; curnode && i < pos; curnode = curnode->next)
            i++;
    else
        for (curnode = node; curnode && i > -pos; curnode = curnode->prev)
            i--;

    return curnode;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(Node<T>* _node = NULL): node(_node) {}

template <typename T>
LinkedListIterator<T>::operator Node<T>*()
{
    return node;
}

template <typename T>
LinkedListIterator<T>::operator T*()
{
    return &node->data;
}

template <typename T>
T& LinkedListIterator<T>::operator*()
{
    return node->data;
}

template <typename T>
T* LinkedListIterator<T>::operator->()
{
    return &node->data;
}

template <typename T>
T& LinkedListIterator<T>::operator[](size_t pos)
{
    return node_at(pos)->data;
}

template <typename T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T>& other) const
{
    return node == other.node;
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T>& other) const
{
    return node != other.node;
}

template <typename T>
bool LinkedListIterator<T>::operator<=(const LinkedListIterator<T>& other) const
{
    Node<T>* curnode = node;

    while (curnode && curnode != other.node)
        curnode = curnode->next;

    return curnode == other.node;
}

template <typename T>
bool LinkedListIterator<T>::operator<(const LinkedListIterator<T>& other) const
{
    Node<T>* curnode = node;

    while (curnode && curnode != other.node)
        curnode = curnode->next;

    return curnode == other.node;
}

template <typename T>
bool LinkedListIterator<T>::operator>=(const LinkedListIterator<T>& other) const
{
    Node<T>* curnode = node;

    while (curnode && curnode != other.node)
        curnode = curnode->prev;

    return curnode == other.node;
}

template <typename T>
bool LinkedListIterator<T>::operator>(const LinkedListIterator<T>& other) const
{
    Node<T>* curnode = node;

    while (curnode && curnode != other.node)
        curnode = curnode->prev;

    return curnode == other.node && node != other.node;
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator+(size_t pos) const
{
    return LinkedListIterator(node_at(pos));
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator-(size_t pos) const
{
    return LinkedListIterator(node_at(-pos));
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator+=(size_t pos)
{
    node = node_at(pos);
    return *this;
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator-=(size_t pos)
{
    node = node_at(-pos);
    return *this;
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
    node = node->next;
    return *this;
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator--()
{
    node = node->prev;
    return *this;
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator++(int)
{
    LinkedListIterator<T> oldvalue = *this;
    operator++();
    return oldvalue;
}

template <typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator--(int)
{
    LinkedListIterator<T> oldvalue = *this;
    operator--();
    return oldvalue;
}

template <typename T>
void LinkedList<T>::copy(size_t n, const T& data)
{
    for (size_t i = 0; i < n; i++)
        push_back(data);
}

template <typename T>
void LinkedList<T>::copy(const T* arr, size_t arrlen)
{
    for (size_t i = 0; i < arrlen; i++)
        push_back(arr[i]);
}

template <typename T>
void LinkedList<T>::copy(const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    for (LinkedListIterator<T> i = from; i != to; i++)
        push_back(*i);
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    for (LinkedListIterator<T> i = other.begin(); i != other.end(); i++)
        push_back(*i);
}

template <typename T>
void LinkedList<T>::destroy()
{
    while (pop_front());
}

template <typename T>
LinkedList<T>::LinkedList(): frontnode(NULL), backnode(NULL) {}

template <typename T>
LinkedList<T>::LinkedList(size_t n, const T& data)
{
    copy(n, data);
}

template <typename T>
LinkedList<T>::LinkedList(const T* arr, size_t arrlen)
{
    copy(arr, arrlen);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    copy(from, to);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    copy(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    destroy();
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::begin()
{
    return LinkedListIterator<T>(frontnode);
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::end()
{
    return empty() ? begin() : LinkedListIterator<T>(backnode->next);
}

template <typename T>
bool LinkedList<T>::empty() const
{
    return !frontnode;
}

template <typename T>
size_t LinkedList<T>::size() const
{
    size_t len = 0;

    for (LinkedListIterator<T> i = begin(); i != end(); i++)
        len++;

    return len;
}

template <typename T>
T& LinkedList<T>::front()
{
    return frontnode->data;
}

template <typename T>
T& LinkedList<T>::back()
{
    return backnode->data;
}

template <typename T>
void LinkedList<T>::assign(size_t n, const T& data)
{
    clear();
    copy(n, data);
}

template <typename T>
void LinkedList<T>::assign(const T* arr, size_t arrlen)
{
    clear();
    copy(arr, arrlen);
}

template <typename T>
void LinkedList<T>::assign(const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    clear();
    copy(from, to);
}

template <typename T>
void LinkedList<T>::push_front(const T& data)
{
    Node<T>* node = new Node<T>(data, NULL, frontnode);

    if (empty())
        frontnode = backnode = node;
    else
    {
        frontnode->prev = node;
        frontnode = node;
    }
}

template <typename T>
void LinkedList<T>::push_back(const T& data)
{
    Node<T>* node = new Node<T>(data, backnode);

    if (empty())
        backnode = frontnode = node;
    else
    {
        backnode->next = node;
        backnode = node;
    }
}

template <typename T>
bool LinkedList<T>::pop_front()
{
    if (empty())
        return false;
    else
    {
        Node<T>* newfrontnode = frontnode->next;
        newfrontnode->prev = NULL;
        delete frontnode;
        frontnode = newfrontnode;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::pop_back()
{
    if (empty())
        return false;
    else
    {
        Node<T>* newbacknode = backnode->prev;
        newbacknode->next = NULL;
        delete backnode;
        backnode = newbacknode;
        return true;
    }
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const T& data)
{
    Node<T>* node = atpos;

    if (node)
    {
        Node<T>* newnode = new Node<T>(data, node, node->next);
        node->next->prev = newnode;
        node->next = newnode;
        return LinkedListIterator<T>(newnode);
    }
    else
        return LinkedListIterator<T>();
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, size_t n, const T& data)
{
    Node<T>* node = atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (size_t i = 0; i < n; i++)
        {
            Node<T>* newnode = new Node<T>(data, node);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
        oldnextnode->prev = node;
    }
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const T* arr, size_t arrlen)
{
    Node<T>* node = atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (size_t i = 0; i < arrlen; i++)
        {
            Node<T>* newnode = new Node<T>(arr[i], node);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
        oldnextnode->prev = node;
    }
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    Node<T>* node = atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (LinkedListIterator<T> i = from; i != to; i++)
        {
            Node<T>* newnode = new Node<T>(*i, node);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
        oldnextnode->prev = node;
    }
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::erase(const LinkedListIterator<T>& atpos)
{
    if (empty())
        return LinkedListIterator<T>();
    else if (atpos == begin())
    {
        pop_front();
        return begin();
    }
    else if (atpos == LinkedListIterator<T>(backnode))
    {
        pop_back();
        return LinkedListIterator<T>(backnode);
    }
    else
    {
        Node<T>* node = atpos;

        if (node)
        {
            Node<T>* nextnode = node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            return LinkedListIterator<T>(nextnode);
        }
        else
            return LinkedListIterator<T>();
    }
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::erase(const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    if (empty())
        return LinkedListIterator<T>();
    else
    {
        LinkedListIterator<T> i = from;

        while (i != end() && i != to)
            i = erase(i);

        return i;
    }
}

template <typename T>
void LinkedList<T>::swap(const LinkedList<T>& other)
{
    LinkedList<T> x(*this);
    operator=(other);
    other.operator=(x);
}

template <typename T>
void LinkedList<T>::clear()
{
    destroy();
}

template <typename T>
void LinkedList<T>::splice(const LinkedListIterator<T>& atpos, LinkedList<T>& other)
{
    insert(atpos, other.begin(), other.end());
    other.clear();
}

template <typename T>
void LinkedList<T>::splice(const LinkedListIterator<T>& atpos, LinkedList<T>& other, const LinkedListIterator<T>& other_atpos)
{
    if (other_atpos != other.end())
    {
        insert(atpos, *other_atpos);
        other.erase(other_atpos);
    }
}

template <typename T>
void LinkedList<T>::splice(const LinkedListIterator<T>& atpos, LinkedList<T>& other, const LinkedListIterator<T>& other_from, const LinkedListIterator<T>& other_to)
{
    insert(atpos, other_from, other_to);
    other.erase(other_from, other_to);
}

template <typename T>
void LinkedList<T>::reverse()
{
    for (Node<T>* node = frontnode; node; node = node->next)
    {
        Node<T>* newprevnode = node->next;
        node->next = node->prev;
        node->prev = newprevnode;
    }

    Node<T>* newfrontnode = backnode;
    backnode = frontnode;
    frontnode = newfrontnode;
}
