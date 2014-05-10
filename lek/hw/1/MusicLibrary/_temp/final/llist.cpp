#include <cstddef>
#include "llist.h"
#pragma once

template <typename T>
Node<T>::Node(const T& _data, Node<T>* _next = NULL): data(_data), next(_next) {}

template <typename T>
Node<T>* LinkedListIterator<T>::node_at(size_t pos)
{
    size_t i = 0;
    Node<T>* curnode;

    for (curnode = node; curnode && i < pos; curnode = curnode->next)
        i++;

    return curnode;
}

template <typename T>
LinkedListIterator<T>::LinkedListIterator(const Node<T>* _node = NULL): node(_node) {}

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
LinkedListIterator<T> LinkedListIterator<T>::operator+(size_t pos) const
{
    return LinkedListIterator(node_at(pos));
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator+=(size_t pos)
{
    node = node_at(pos);
    return *this;
}

template <typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
    node = node->next;
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
void LinkedList<T>::base_reverse(Node<T>* node)
{
    if (node->next->next)
        base_reverse(node->next);

    node->next->next = node;
    node->next = NULL;
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
    Node<T>* node = new Node<T>(data, frontnode);
    frontnode = empty() ? backnode = node : node;
}

template <typename T>
void LinkedList<T>::push_back(const T& data)
{
    Node<T>* node = new Node<T>(data);

    if (empty())
        frontnode = backnode = node;
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
        Node<T>* prevback;

        for (prevback = frontnode; prevback && prevback->next != backnode; prevback = prevback->next);

        delete backnode;
        prevback->next = NULL;
        return true;
    }
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const T& data)
{
    Node<T>* node = (Node<T>*) atpos;

    if (node)
    {
        Node<T>* newnode = new Node<T>(data, node->next);
        node->next = newnode;
        return LinkedListIterator<T>(newnode);
    }
    else
        return LinkedListIterator<T>();
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, size_t n, const T& data)
{
    Node<T>* node = (Node<T>*) atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (size_t i = 0; i < n; i++)
        {
            Node<T>* newnode = new Node<T>(data);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
    }
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const T* arr, size_t arrlen)
{
    Node<T>* node = (Node<T>*) atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (size_t i = 0; i < arrlen; i++)
        {
            Node<T>* newnode = new Node<T>(arr[i]);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
    }
}

template <typename T>
void LinkedList<T>::insert(const LinkedListIterator<T>& atpos, const LinkedListIterator<T>& from, const LinkedListIterator<T>& to)
{
    Node<T>* node = (Node<T>*) atpos;

    if (node)
    {
        Node<T>* oldnextnode = node->next;

        for (LinkedListIterator<T> i = from; i != to; i++)
        {
            Node<T>* newnode = new Node<T>(*i);
            node->next = newnode;
            node = newnode;
        }

        node->next = oldnextnode;
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
    else
    {
        LinkedListIterator<T> i = begin(), atend = end();

        while (i + 1 != atend && i + 1 != atpos)
            i++;

        if (i + 1 == atpos)
        {
            Node<T> *prevnode = (Node<T>*) i, *node = prevnode->next;
            prevnode->next = node->next;
            delete node;
            return LinkedListIterator<T>(node);
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
        LinkedListIterator<T> i = from, atend = end();

        while (i != atend && i != to)
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
    if (other_atpos)
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
    if (frontnode && frontnode->next)
        base_reverse(frontnode);

    Node<T>* newfrontnode = backnode;
    backnode = frontnode;
    frontnode = newfrontnode;
}
