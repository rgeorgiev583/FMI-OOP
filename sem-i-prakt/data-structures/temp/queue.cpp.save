#include <cstddef>
#include "queue.h"

Node::Node(int _data = DEFAULT, Node* _next = NULL): data(_data), next(_next) {}

void Queue::copy(const Queue& q)
{
    Node* last = NULL;

    for (Node* i = q.front; i; i = i->next)
    {
        Node* node = new Node(i->data);

        if (last)
            last->next = node;
        else
            front = node;

        last = node;
    }

    back = last;
}

void Queue::destroy()
{
    while(pop());
}

Queue::Queue(): front(NULL), back(NULL) {}

Queue::Queue(const Queue& q)
{
    copy(q);
}

Queue& Queue::operator=(const Queue& q)
{
    if (this != &q)
    {
        destroy();
        copy(q);
    }

    return *this;
}

Queue::~Queue()
{
    destroy();
}

bool Queue::empty() const
{
    return !front;
}

int Queue::peek() const
{
    return empty() ? DEFAULT : front->data;
}

void Queue::push(int n)
{
    Node* node = new Node(n);

    if (empty())
        front = back = node;
    else
    {
        back->next = node;
        back = node;
    }
}

bool Queue::pop()
{
    if (empty())
        return false;
    else
    {
        Node* newfront = front->next;
        delete front;
        front = newfront;
        return true;
    }
}
