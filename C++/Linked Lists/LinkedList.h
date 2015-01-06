/* Simple Non-circular Singly Linked List */

#include <iostream>
using std::cout; using std::endl;


template <typename T>
struct Node
{
    T data;
    Node* next = nullptr;
};


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void append(const T &val);
    void remove(const T &val);
    int size();

private:
    Node<T>* head;
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* current = head;
    while (current && current->next) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

template <typename T>
void LinkedList<T>::append(const T &val)
{
    Node<T>* tail = new Node<T>;
    tail->data = val;
    tail->next = nullptr;

    if (!head) {
        head = tail;
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = tail;
    }
}

template <typename T>
void LinkedList<T>::remove(const T &val)
{
    // list is empty
    if (!head) {
        return;
    }
    // only one element in list
    else if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    // head is desired element
    else if (head->data == val) {
        Node<T>* prev = head;
        head = head->next;
        delete prev;
        return;
    }

    Node<T>* current = head;
    Node<T>* prev;

    while (current->next && current->next->data != val) {
        prev = current;
        current = current->next;
    }

    // item not found after all nodes searched
    if (!current->next && current->data != val) {
        return;
    }
    // item is the last node
    else if (!current->next && current->data == val) {
        delete current;
        prev->next = nullptr;
        return;
    }

    prev = current;
    current = current->next;    // now holding desired value
    prev->next = current->next;
    delete current;
}

template <typename T>
int LinkedList<T>::size()
{
    if (!head) { return 0; }

    int count = 1;
    Node<T>* current = head;
    while (current->next) {
        ++count;
        current = current->next;
    }
    return count;
}

#endif