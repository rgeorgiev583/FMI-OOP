#include <cstddef>
#include "queue.h"

Node::Node(int _data = DEFAULT, Node* _next = NULL): data(_data), next(_next) {}

void Queue::copy(const Queue& q)
{
    if (!q.empty())
    {
        frontnode = backnode = new Node(q.frontnode->data);

        for (Node* i = q.frontnode->next; i; i = i->next)
        {
            Node* node = new Node(i->data);
            backnode->next = node;
            backnode = node;
        }
    }
}

void Queue::destroy()
{
    while(pop());
}

Queue::Queue(): frontnode(NULL), backnode(NULL) {}

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
    return !frontnode;
}

int Queue::front() const
{
    return empty() ? DEFAULT : frontnode->data;
}

void Queue::push(int data)
{
    Node* node = new Node(data);

    if (empty())
        frontnode = backnode = node;
    else
    {
        backnode->next = node;
        backnode = node;
    }
}

bool Queue::pop()
{
    if (empty())
        return false;
    else
    {
        Node* newfrontnode = frontnode->next;
        delete frontnode;
        frontnode = newfrontnode;
        return true;
    }
}
