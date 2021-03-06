#include <cstddef>
#include "llist.h"

Node::Node(int _data = 0, Node* _next = NULL): data(_data), next(_next) {}

Node* LinkedList::base_splice(const LinkedList& list, Node*& atnode)
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

void LinkedList::copy(const LinkedList& list)
{
    back = base_splice(list, front);
}

void LinkedList::destroy()
{
    while(pop_front());
}

LinkedList::LinkedList(): front(NULL), back(NULL) {}

LinkedList::LinkedList(const LinkedList& list)
{
    copy(list);
}

LinkedList& LinkedList::operator=(const LinkedList& list)
{
    if (this != &list)
    {
        destroy();
        copy(list);
    }

    return *this;
}

LinkedList::~LinkedList()
{
    destroy();
}

size_t LinkedList::size() const
{
    size_t len = 0;

    for (Node* i = front; i; i = i->next)
        len++;

    return len;
}

int LinkedList::at(size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    return node->data;
}

int LinkedList::operator[](size_t pos)
{
    return at(pos);
}

void LinkedList::push_front(int data)
{
    Node* node = new Node(data, front);

    if (size() == 0)
        front = back = node;
    else
        front = node;
}

void LinkedList::push_back(int data)
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

void LinkedList::push_at(int data, size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    Node *newnode = new Node(data, node->next);
    node->next = newnode;
}

bool LinkedList::pop_front()
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

bool LinkedList::pop_back()
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

bool LinkedList::pop_at(size_t pos)
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

void LinkedList::splice(const LinkedList& list, size_t pos)
{
    size_t i = 0;
    Node* node;

    for (node = front; node && i < pos; node = node->next)
        i++;

    back = base_splice(list, node);
}
