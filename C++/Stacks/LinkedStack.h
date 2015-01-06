/* Stack implementation using linked list (first item in list is top of stack) */

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>


template <typename T>
class LinkedStack
{
    public:
        LinkedStack();
        ~LinkedStack();
        void push(const T &value);
        T pop();
        void clear();
        bool isEmpty();
        void show() const;
    private:
        struct _node
        {
            T val;
            _node* next;
        };

        _node* root;
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    root = NULL;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    if (root) { clear(); }
}

// Add item to top of stack
template <typename T>
void LinkedStack<T>::push(const T &value)
{
    _node* new_node = new _node;
    new_node->val = value;
    
    if (!root)    // stack is empty
    {
        new_node->next = NULL;
        root = new_node;
    }
    else
    {
        new_node->next = root;
        root = new_node;
    }
}

// Remove and return item from top of stack
template <typename T>
T LinkedStack<T>::pop()
{
    T out_val = root->val;
    if (!root->next) // only one item in stack
    {
        delete root;
        root = NULL;
    }
    else
    {
        _node* current = root;
        root = current->next;
        delete current;
    }

    return out_val;
}

// Empties stack and resets root to NULL
template <typename T>
void LinkedStack<T>::clear()
{
    _node* current = root;
    while (current && current->next)
    {
        root = current->next;
        delete current;
        current = root;
    }
    root = NULL;
}

template <typename T>
bool LinkedStack<T>::isEmpty()
{
    if (!root) { return true; }
    else { return false; }
}

template <typename T>
void LinkedStack<T>::show() const
{
    _node* current = root;
    while (current)
    {
        std::cout << current->val << std::endl;
        current = current->next;
    }
}

#endif