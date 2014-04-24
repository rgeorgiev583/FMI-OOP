#include <cstddef>
#include "llist.h"

Node::Node(const Filter& _data, Node* _next = NULL): data(_data), next(_next) {}

Node* LinkedFilterList::base_splice(const LinkedFilterList& list, Node*& atnode)
{
    if (list.size() == 0)
        return atnode;
    else
    {
        Node* lastnode = atnode = new Node(list.front->data);

        for (Node* i = list.front->next; i; i = i->next)
        {
            Node* node = new Node(i->data);
            lastnode->next = node;
            lastnode = node;
        }

        return lastnode;
    }
}

void LinkedFilterList::copy(const LinkedFilterList& list)
{
    back = base_splice(list, front);
}

void LinkedFilterList::destroy()
{
    while(pop_front());
}

LinkedFilterList::LinkedFilterList(): front(NULL), back(NULL) {}

LinkedFilterList::LinkedFilterList(const LinkedFilterList& list)
{
    copy(list);
}

LinkedFilterList& LinkedFilterList::operator=(const LinkedFilterList& list)
{
    if (this != &list)
    {
        destroy();
        copy(list);
    }

    return *this;
}

LinkedFilterList::~LinkedFilterList()
{
    destroy();
}

size_t LinkedFilterList::size()
{
    size_t len = 0;

    for (Node* i = front; i; i = i->next)
        len++;

    return len;
}

Filter& LinkedFilterList::at(size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    return node->data;
}

Filter& LinkedFilterList::operator[](size_t pos)
{
    return at(pos);
}

void LinkedFilterList::push_front(const Filter& data)
{
    Node* node = new Node(data, front);

    if (size() == 0)
        front = back = node;
    else
        front = node;
}

void LinkedFilterList::push_back(const Filter& data)
{
    Node* node = new Node(data);

    if (size() == 0)
        front = back = node;
    else
    {
        back->next = node;
        back = node;
    }
}

void LinkedFilterList::push_at(const Filter& data, size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    Node *newnode = new Node(data, node->next);
    node->next = newnode;
}

bool LinkedFilterList::pop_front()
{
    if (size() == 0)
        return false;
    else
    {
        Node* newfront = front->next;
        delete front;
        front = newfront;
        return true;
    }
}

bool LinkedFilterList::pop_back()
{
    if (size() == 0)
        return false;
    else
    {
        Node* prevback;

        for (prevback = front; prevback && prevback->next != back; prevback = prevback->next);

        delete back;
        prevback->next = NULL;
        return true;
    }
}

bool LinkedFilterList::pop_at(size_t pos)
{
    if (size() == 0)
        return false;
    else
    {
        size_t i = 0;
        Node* prevnode;

        for (prevnode = front; prevnode && i - 2 < pos; prevnode = prevnode->next)
            i++;

        Node* node = prevnode->next;
        prevnode->next = node->next;
        delete node;
        return true;
    }
}

void LinkedFilterList::splice(const LinkedFilterList& list, size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    back = base_splice(list, node);
}
