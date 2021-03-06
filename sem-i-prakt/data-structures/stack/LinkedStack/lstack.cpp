#include <cstring>
#include "lstack.h"

void Stack::copy(const Stack& s)
{
    Node* last = NULL;

    for (Node* i = s.top; i; i=i->next)
    {
        Node* elem = new Node(i->data);

        if (last)
            last->next = elem;
        else
            top = elem;

        last = elem;
    }
}

void Stack::destroy()
{
    while(pop());
}

Stack::Stack(): top(NULL) {}

Stack::Stack(const Stack& s)
{
    copy(s);
}

Stack& Stack::operator=(const Stack& s)
{
    if (this != &s)
    {
        destroy();
        copy(s);
    }

    return *this;
}

Stack::~Stack()
{
    destroy();
}

bool Stack::empty() const
{
    return !top;
}

char* Stack::peek() const
{
    char* s = NULL;
    if (!empty())
    {
        s = new char[strlen(top->data) + 1];
        strcpy(s, top->data);
    }
    return s;
}

void Stack::push(const char* s)
{
    Node* newtop = new Node(s, top);
    top = newtop;
}

bool Stack::pop()
{
    if (empty())
        return false;
    else
    {
        Node* newtop = top->next;
        delete top;
        top = newtop;
        return true;
    }
}
