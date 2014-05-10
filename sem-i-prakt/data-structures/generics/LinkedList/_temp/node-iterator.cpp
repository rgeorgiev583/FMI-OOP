
template<typename T>
class LinkedListIterator
{
    Node<T>* node;

    Node<T>* node_at(size_t) const;

public:
    LinkedListIterator(const Node<T>* = NULL);

    T& operator*();
    T& operator[](size_t);

    LinkedListIterator<T> operator+(size_t) const;
    LinkedListIterator<T>& operator+=(size_t);
    LinkedListIterator<T>& operator++();
    LinkedListIterator<T>& operator++(int);

    friend bool operator==(const LinkedListIterator<T>&, const LinkedListIterator<T>&) const;
    friend bool operator!=(const LinkedListIterator<T>&, const LinkedListIterator<T>&) const;
};

template<typename T>
Node<T>* LinkedListIterator<T>::node_at(size_t pos) const
{
    size_t i = 0;
    Node<T>* curnode;

    for (curnode = node; curnode && i < pos; curnode = curnode->next)
        i++;

    return curnode;
}

template<typename T>
LinkedListIterator(const Node<T>* newnode = NULL): node(newnode) {}

template<typename T>
T& LinkedListIterator<T>::operator*()
{
    return node->data;
}

template<typename T>
T& LinkedListIterator<T>::operator[](size_t pos)
{
    return node_at(pos)->data;
}

template<typename T>
LinkedListIterator<T> LinkedListIterator<T>::operator+(size_t pos) const
{
    return LinkedListIterator(node_at(pos));
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator+=(size_t pos)
{
    node = node_at(pos);
    return *this;
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++()
{
    return operator+=(1);
}

template<typename T>
LinkedListIterator<T>& LinkedListIterator<T>::operator++(int)
{
    return operator++();
}

template<typename T>
bool operator==(const LinkedListIterator<T>& l1, const LinkedListIterator<T>& l2) const
{
    return l1.node == l2.node;
}

template<typename T>
bool operator!=(const LinkedListIterator<T>& l1, const LinkedListIterator<T>& l2) const
{
    return l1.node != l2.node;
}
