#ifndef ALGORITHMS_2021_STACKLIST_H
#define ALGORITHMS_2021_STACKLIST_H

#include "Stack.h"

template <class T>
class StackList : public Stack<T>{

private:

    struct Node{

        T item_;

        Node* next_;

        explicit Node(T item, Node* next = nullptr);

        bool hasNext();
    };

    Node* head_;

    Node* top_;

public:

    StackList();
    ~StackList() = default;
    void push(const T& e);
    T pop();
    bool isEmpty();
    void print();

};


template<class T>
T StackList<T>::pop() {
    if(head_ == nullptr) return 0;

    T res = head_->item_;
    Node* temp = head_->next_;

    delete head_;

    head_ = temp;

    return res;
}

template<class T>
bool StackList<T>::isEmpty() {
    return false;
}

template<class T>
void StackList<T>::push(const T &e) {
    Node* temp = new Node(e);
    temp->next_ = head_;
    head_ = temp;
}

template<class T>
void StackList<T>::print() {
    Node* temp = head_;
    std::cout << temp->item_ << " ";
    while(temp->hasNext()){
        temp = temp->next_;
        std::cout << temp->item_ << " ";
    };
    std::cout << std::endl;
}

template<class T>
StackList<T>::StackList() {
    head_ = nullptr;
}

template<class T>
bool StackList<T>::Node::hasNext() {
    return next_ != nullptr;
}

template<class T>
StackList<T>::Node::Node(T item, StackList::Node *next) : item_(item), next_(next){}

#endif //ALGORITHMS_2021_STACKLIST_H