//
// Created by Foko on 02.04.2022.
//

#include "Stack.h"

char getPriority (std::string& op) {
    if (op == "(") {
        return 0;
    } else if (op == ")") {
        return 1;
    } else if (op == "+" || op == "-") {
        return 2;
    } else if (op == "*" || op == "/") {
        return 3;
    } else if (op == "^") {
        return 4;
    } else {
        return -1;
    }
}

bool getSpaces(const std::string& str, size_t& index) {
    if (str[index] == ' ') {
        ++index;
        getSpaces(str, index);
        return true;
    } else {
        return false;
    }
}

bool getOperator(const std::string& str, size_t& index) {
    static char* operators = "+-*/()^";
    for (char* c = operators; *c != '\0'; ++c) {
        if (*c == str[index]) {
            ++index;
            return true;
        }
    }
    return false;
}

bool getInt (const std::string& str, size_t& index) {
    if (str[index] >= '0' && str[index] <= '9') {
        getInt(str, ++index);
        return true;
    } else {
        return false;
    }
}

template<typename T>
StackArray<T>::StackArray(int32_t size) {
    array = new T[size];
    length = size;
    top = -1;
}

template<typename T>
int StackArray<T>::evaluatePostfix(const std::string &postfix, size_t stackSize) {
    size_t index = 0;  ;
    while (index != postfix.length()) {
        size_t old_index = index;
        if (getInt(postfix, index)) {
            push(postfix.substr(old_index, index-old_index));
        }
        if (getOperator(postfix, index)) {
            std::string buf = postfix.substr(old_index, index - old_index);
            const char* op = buf.c_str();
            int temp = std::stod(pop());
            switch (*op) {
                case '+': {
                    push(std::to_string(std::stoi(pop()) + temp));
                    break;
                }
                case '-': {
                    push(std::to_string(std::stoi(pop()) - temp));
                    break;
                }
                case '*': {
                    push(std::to_string(std::stoi(pop()) * temp));
                    break;
                }
                case '/': {
                    push(std::to_string(std::stoi(pop()) / temp));
                    break;
                }
            }
        }
        if (getSpaces(postfix, index)) {
            continue;
        }
        throw "UNKNOWN SYMBOLS";
    }
    if (top == 0) {
        return std::stoi(pop());
    } else {
        while (!isEmpty()) {
            pop();
        }
        throw "INCOMPLETE SENTENCE ";
    }
}

template<typename T>
bool StackArray<T>::checkBraces(const std::string &infix) {
    for (char c: infix) {
        if (c == '(') {
            push(""); // не важно, что пушить, главное -- куда, ауф
        } else if (c == ')') {
            if (!isEmpty()) {
                pop();
            } else{
                return false;
            }
        } else {
            ;
        }
    }
    return true;
}

template<typename T>
bool StackArray<T>::getPostfixFromInfix(const std::string &infix, std::string &postfix, const size_t stackSize) {
    size_t index = 0;
    size_t old_index = index;
    while (index != infix.length()) {
        if (getInt(infix, index)) {
            postfix += infix.substr(old_index, index - old_index);
            postfix += " ";
        } else if (getOperator(infix, index)) {
            std::string op = infix.substr(old_index, index - old_index);
            if (getPriority(op) == 1) {
                while (getPriority(array[top]) != 0) {
                    postfix += pop();
                    postfix += " ";
                }
                pop();
            } else if (getPriority(op) == 0) {
                push(op);
            } else if (!isEmpty()) {
                while (getPriority(array[top]) >= getPriority(op)) {
                    postfix += pop();
                    postfix += " ";
                }
                push(op);
            } else {
                push(op);
            }
        } else if (getSpaces(infix, index)) {
            ;
        } else {
            while (top >= 0) {
                pop();
            }
            return false;
        }
        old_index = index;
    }
    while (!isEmpty()) {
        postfix += pop();
        postfix += " ";
    }
    return true;
}

template<typename T>
bool StackArray<T>::isEmpty() {
    return top < 0;
}

template<typename T>
StackArray<T>::~StackArray() {
    delete[] array;
}

template<typename T>
void StackArray<T>::push(const T &element) {
    if (top < length) {
        array[++top] = element;
    } else {
        throw "STACKOVERFLOW";
    }
}

template<typename T>
T StackArray<T>::pop() {
    if (top >= 0) {
        return array[top--];
    } else {
        top = -1;
        throw "STACKUNDERFLOW";
    }
}
