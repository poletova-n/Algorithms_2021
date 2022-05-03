#ifndef ALGORITHMS_2021_STACKARRAY_H
#define ALGORITHMS_2021_STACKARRAY_H

#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class StackArray : public Stack<T>{

private:

    T* array_;

    size_t curSize_;

    size_t size_;

    void swap(StackArray<T>& other);

public:

    explicit StackArray(const int& size = 100);
    ~StackArray() = default;
    void push(const T& e);
    T pop();
    T top();
    bool isEmpty();
    void print();

    size_t getCurSize() const;

};

template<class T>
void StackArray<T>::swap(StackArray<T> &other) {
    std::swap(curSize_, other.curSize_);
    std::swap(size_, other.size_);
    std::swap(array_, other.array);
}

template<class T>
StackArray<T>::StackArray(const int &size) : curSize_(0), size_(size) {
    try {
        try {
            array_ = new T[size];
        } catch (std::exception &e) {
            throw WrongStackSize();
        }
    }
    catch (std::exception &e) {
        system("cls");
        std::cerr << std::endl << e.what() << std::endl;
        exit(1);
    }
}

template<class T>
void StackArray<T>::push(const T &e) {
    try {
        if(curSize_ == size_){
            throw StackOverflow();
        }
    }catch(std::exception &e){
        system("cls");
        std::cerr << std::endl << e.what() << std::endl;
        exit(1);
    }
    array_[curSize_] = e;
    curSize_++;
}

template<class T>
T StackArray<T>::pop() {
    try {
        if(curSize_ < 1){
            throw StackUnderflow();
        }
    }catch (std::exception &e){
        system("cls");
        std::cerr << std::endl << e.what() << std::endl;
        exit(1);
    }
    T res = array_[curSize_ - 1];
    curSize_--;
    return res;
}

template<class T>
bool StackArray<T>::isEmpty() {
    return curSize_ == 0;
}

template<class T>
void StackArray<T>::print() {

    for (int i = curSize_ - 1; i >= 0; --i) {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T StackArray<T>::top() {
    return array_[curSize_-1];
}

template<class T>
size_t StackArray<T>::getCurSize() const {
    return curSize_;
}


#endif //ALGORITHMS_2021_STACKARRAY_H
