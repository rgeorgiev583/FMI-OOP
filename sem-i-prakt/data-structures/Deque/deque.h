#pragma once

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

class
