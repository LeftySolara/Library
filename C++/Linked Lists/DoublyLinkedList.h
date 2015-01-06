/* Simple Non-circular Doubly Linked List */

#include <iostream>
using std::cout; using std::endl;


template <typename T>
struct Node
{
    T data;
    Node* prev = nullptr;
    Node* next = nullptr;
};


#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(const T &val);
    void remove(const T &val);
    int size();

private:
    Node<T>* head;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
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
void DoublyLinkedList<T>::append(const T &val)
{
    Node<T>* tail = new Node<T>;
    tail->data = val;

    if (!head) {
        head = tail;
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = tail;
        tail->prev = current;
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(const T &val)
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
        Node<T>* old_head = head;
        head = head->next;
        head->prev = nullptr;
        delete old_head;
        return;
    }

    Node<T>* current = head;

    while (current->next && current->next->data != val) {
        current = current->next;
    }

    // item not found after all nodes searched
    if (!current->next && current->data != val) {
        return;
    }
    // item is the last node
    else if (!current->next && current->data == val) {
        current->prev->next = nullptr;
        delete current;
        return;
    }

    // item is somewhere in middle of list
    current->prev->next = current->next;
    delete current;
}

template <typename T>
int DoublyLinkedList<T>::size()
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