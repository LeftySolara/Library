/* Stack implementation using arrays */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>

template <typename T>
class ArrayStack
{
    public:
        ArrayStack(int size);
        ~ArrayStack();
        void push(const T &value);
        T pop();
        bool stackIsFull();
        bool stackIsEmpty();
        int get_top() { return top; }
    private:
        T* contents;
        int max_size;
        int top;  // index of element at top of stack
};

template <typename T>
ArrayStack<T>::ArrayStack(int size)
{
    max_size = size;
    contents = new T [max_size];
    top = -1;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    contents = NULL;
}

template <typename T>
void ArrayStack<T>::push(const T &value)
{
    if (stackIsFull())
    {
        std::cout << "Cannot push element on stack: stack is full\n" << std::endl;
        exit(1);
    }

    contents[top+1] = value;
    ++top;
}

template <typename T>
T ArrayStack<T>::pop()
{
    if (stackIsEmpty())
    {
        std::cout << "Cannot pop from stack: stack is empty\n" << std::endl;
        exit(1);
    }

    return contents[top--];
}

template <typename T>
bool ArrayStack<T>::stackIsFull()
{
    return top >= max_size - 1;
}

template <typename T>
bool ArrayStack<T>::stackIsEmpty()
{
    return top == -1;
}

#endif