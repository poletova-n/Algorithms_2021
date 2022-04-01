//
// Created by Foko on 02.04.2022.
//

#ifndef ONE_WAY_LIST_STACK_H
#define ONE_WAY_LIST_STACK_H

#include <vector>
#include <cmath>
#include <iomanip>

template <typename T> class Stack {
public:
    virtual ~Stack () = default;
    virtual void push (const T& element) = 0;
    virtual T pop () = 0;
    virtual bool isEmpty () = 0;
};

template <typename T> class StackArray: Stack<T> {
public:
    T* array;
    int32_t top;
    int32_t length;
public:
    explicit StackArray (int32_t size);

    ~StackArray ();

    void push (const T& element);

    T pop ();

    bool isEmpty ();

    bool getPostfixFromInfix (const std::string& infix, std::string& postfix, size_t stackSize);

    bool checkBraces(const std::string& infix);

    int evaluatePostfix (const std::string& postfix, size_t stackSize);
};

#endif //ONE_WAY_LIST_STACK_H
