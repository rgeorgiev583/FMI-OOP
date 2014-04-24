#include <cstddef>
#include "llist.h"
#pragma once

template<typename T> Node<T>::Node(const T& _data, Node<T>* _next = NULL): data(_data), next(_next) {}

template<typename T> void LinkedList<T>::copy(const LinkedList<T>& list)
{
    backnode = base_splice(list, frontnode);
}

template<typename T> void LinkedList<T>::destroy()
{
    while(pop_front());
}

template<typename T> T* LinkedList<T>::base_at(size_t pos)
{
    size_t i = 0;
    Node<T>* node;

    for (node = frontnode; node && i < pos; node = node->next)
        i++;

    return &node->data;
}

template<typename T> Node<T>* LinkedList<T>::base_splice(const LinkedList<T>& list, Node<T>*& atnode)
{
    if (list.empty())
        return atnode;
    else
    {
        Node<T>* lastnode = atnode = new Node<T>(list.frontnode->data);

        for (Node<T>* i = list.frontnode->next; i; i = i->next)
        {
            Node<T>* node = new Node<T>(i->data);
            lastnode->next = node;
            lastnode = node;
        }

        return lastnode;
    }
}

template<typename T> void LinkedList<T>::base_reverse(Node<T>* node)
{
    if (node->next->next)
        base_reverse(node->next);

    node->next->next = node;
    node->next = NULL;
}

template<typename T> LinkedList<T>::LinkedList(): frontnode(NULL), backnode(NULL) {}

template<typename T> LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
    copy(list);
}

template<typename T> LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
    if (this != &list)
    {
        destroy();
        copy(list);
    }

    return *this;
}

template<typename T> LinkedList<T>::~LinkedList<T>()
{
    destroy();
}

template<typename T> bool LinkedList<T>::empty() const
{
    return !frontnode;
}

template<typename T> size_t LinkedList<T>::size() const
{
    size_t len = 0;

    for (Node<T>* i = frontnode; i; i = i->next)
        len++;

    return len;
}

template<typename T> T& LinkedList<T>::front()
{
    return frontnode->data;
}

template<typename T> T& LinkedList<T>::back()
{
    return backnode->data;
}

template<typename T> T& LinkedList<T>::at(size_t pos)
{
    T* atdata = base_at(pos);
    return atdata ? *atdata : back();
}

template<typename T> T& LinkedList<T>::operator[](size_t pos)
{
    return at(pos);
}

template<typename T> void LinkedList<T>::push_front(const T& data)
{
    Node<T>* node = new Node<T>(data, frontnode);
    frontnode = empty() ? backnode = node : node;
}

template<typename T> void LinkedList<T>::push_back(const T& data)
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

template<typename T> void LinkedList<T>::push_at(const T& data, size_t pos)
{
    size_t i = 0;
    Node<T>* node;

    for (node = frontnode; node && i < pos; node = node->next)
        i++;

    Node<T> *newnode = new Node<T>(data, node->next);
    node->next = newnode;
}

template<typename T> bool LinkedList<T>::pop_front()
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

template<typename T> bool LinkedList<T>::pop_back()
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

template<typename T> bool LinkedList<T>::pop_at(size_t pos)
{
    if (empty())
        return false;
    else
    {
        size_t i = 0;
        Node<T>* prevnode;

        for (prevnode = frontnode; prevnode && i - 2 < pos; prevnode = prevnode->next)
            i++;

        Node<T>* node = prevnode->next;
        prevnode->next = node->next;
        delete node;
        return true;
    }
}

template<typename T> void LinkedList<T>::splice(const LinkedList<T>& list, size_t pos)
{
    size_t i = 0;
    Node<T>* node;

    for (node = frontnode; node && i < pos; node = node->next)
        i++;

    backnode = base_splice(list, node);
}

template<typename T> void LinkedList<T>::reverse()
{
    if (frontnode && frontnode->next)
        base_reverse(frontnode);

    Node<T>* newfrontnode = backnode;
    backnode = frontnode;
    frontnode = newfrontnode;
}
