#include <cstddef>
#include "lstack.h"

Node::Node(int _data = DEFAULT, Node* _next = NULL): data(_data), next(_next) {}

void LinkedStack::copy(const LinkedStack& s)
{
    if (!s.empty())
    {
        Node* lastnode = topnode = new Node(s.topnode->data);

        for (Node* i = s.topnode->next; i; i = i->next)
        {
            Node* node = new Node(i->data);
            lastnode->next = node;
            lastnode = node;
        }
    }
}

void LinkedStack::destroy()
{
    while(pop());
}

LinkedStack::LinkedStack(): topnode(NULL) {}

LinkedStack::LinkedStack(const LinkedStack& s)
{
    copy(s);
}

LinkedStack& LinkedStack::operator=(const LinkedStack& s)
{
    if (this != &s)
    {
        destroy();
        copy(s);
    }

    return *this;
}

LinkedStack::~LinkedStack()
{
    destroy();
}

bool LinkedStack::empty() const
{
    return !topnode;
}

int LinkedStack::top() const
{
    return empty() ? DEFAULT : topnode->data;
}

void LinkedStack::push(int data)
{
    Node* newtopnode = new Node(data, topnode);
    topnode = newtopnode;
}

bool LinkedStack::pop()
{
    if (empty())
        return false;
    else
    {
        Node* newtopnode = topnode->next;
        delete topnode;
        topnode = newtopnode;
        return true;
    }
}
