// Simple FIFO queue (linked list implementation)

template <typename T>
struct Node
{
    T data;
    Node* next = nullptr;
};

#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
public:
    Queue();
    ~Queue();
    void enqueue(T val);
    void dequeue();
    T pop();
    int size();
};

template <typename T>
Queue<T>::Queue()
{
    first = nullptr;
    last = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    Node<T>* current = first;
    while (current && current->next) {
        first = current->next;
        delete current;
        current = first;
    }
    first = nullptr;
    last = first;
}

// add given value to end of queue
template <typename T>
void Queue<T>::enqueue(T val)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = val;
    new_node->next = nullptr;

    if (!first) {
        last = new_node;
        first = last;
    }
    else {
        last->next = new_node;
        last = last->next;
    }
}

// remove first node from queue
template <typename T>
void Queue<T>::dequeue()
{
    if (!first) {return;}

    if (first == last) {
        delete first;
        first = nullptr;
        last = first;
        return;
    }

    Node<T>* current = first;
    first = first->next;
    delete current;
}

// remove first node and return its value
template <typename T>
T Queue<T>::pop()
{
    T val = first->data;
    dequeue();
    return val;
}

// return the number of items in queue
template <typename T>
int Queue<T>::size()
{
    if (!first) { return 0; }

    int count = 1;
    Node<T>* current = first;
    while (current->next) {
        ++count;
        current = current->next;
    }
    return count;
}

#endif