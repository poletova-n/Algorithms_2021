//
// Created by Администратор on 22.02.2022.
//

#ifndef ALGORITHMS_2021_STACK_H
#define ALGORITHMS_2021_STACK_H

#include <xstring>
#include <iostream>

template <class T>
class Stack
{

public:
    Stack() = default;
    virtual ~Stack() = default;
    virtual void push(const T& e);
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;
    virtual void print();
};

template<class T>
void Stack<T>::push(const T &e) {}

template<class T>
void Stack<T>::print() {}

#endif //ALGORITHMS_2021_STACK_H
