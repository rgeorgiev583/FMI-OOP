
template <typename T>
void LinkedList<T>::push_at(size_t pos, const T& data)
{
    size_t i = 0;
    Node<T>* node;

    for (node = frontnode; node && i < pos; node = node->next)
        i++;

    Node<T> *newnode = new Node<T>(data, node->next);
    node->next = newnode;
}

template <typename T>
bool LinkedList<T>::pop_at(size_t pos)
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
