    void pop_head(const LinkedListIterator<T>&);
    void pop_tail(const LinkedListIterator<T>&);

    template <typename T>
    void LinkedList<T>::pop_head(const LinkedListIterator<T>& atpos)
    {
        LinkedListIterator<T> atfront(frontnode);
        while (atpos != atfront && pop_front());
    }

    template <typename T>
    void LinkedList<T>::pop_tail(const LinkedListIterator<T>& atpos)
    {
        LinkedListIterator<T> atback(backnode);
        while (atpos != atback && pop_back());
    }
