#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

template <typename T>
class DoublyLinkedList
{
private:
    template<typename U>
    struct Node
    {
        U data;
        Node* next;
        Node* prev;
        Node() = default;
        explicit Node(const U& value) : data(value) {} //prevents implicit type conversion during initialization
    };

private:
    Node<T>* head;//front - start
    Node<T>* tail;//rear - ends
    unsigned int l_size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push(const T& value);
    int size() const;


    class Iterator
    {
    private:
        Node<T>* node;

    public:
        Iterator();
        explicit Iterator(Node<T>* node);
        Iterator(const Iterator& other);

        void operator++();
        void operator--();
        T& operator*();
        bool operator!=(const Iterator& other);
        void operator=(const Iterator& other);
    };

    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(tail);
    }
};

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(DoublyLinkedList::Node<T> *node) : node(node)
{

}

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator(const DoublyLinkedList::Iterator &other) : node(other.node)
{

}

template<typename T>
void DoublyLinkedList<T>::Iterator::operator++() //change+1
{
    node = node->next;
}

template<typename T>
void DoublyLinkedList<T>::Iterator::operator--() //change-1
{
    node = node->prev;
}

template<typename T>
T &DoublyLinkedList<T>::Iterator::operator*() //forgettingdata
{
    return node->data;
}

template<typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const DoublyLinkedList::Iterator &other)
{
    return node->data == other.node->data;
}

template<typename T>
void DoublyLinkedList<T>::Iterator::operator=(const DoublyLinkedList::Iterator &other)
{
    node = other.node;
}

template<typename T>
DoublyLinkedList<T>::Iterator::Iterator() = default;//using compiller version, default realization

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    l_size = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() //delete...
{
    Node<T>* temp = head;
    for (unsigned int i = 0; i < l_size - 1; ++i)
    {
        temp = temp->next;
        delete temp->prev;
    }
    delete temp;
}

template<typename T>
void DoublyLinkedList<T>::push(const T &value)
{
    Node<T>* new_node = new Node<T>(value);

    if (l_size == 0)
    {
        head = tail = new_node;
    }
    else
    {
        Node<T>* temp = tail;
        tail = new Node<T>(value);
        tail->prev = temp;
        temp->next = tail;
    }

    tail->next = head;
    head->prev = tail;

    l_size++;
}

template<typename T>
int DoublyLinkedList<T>::size() const
{
    return l_size;
}


#endif // CIRCULAR_DOUBLY_LINKED_LIST_H
