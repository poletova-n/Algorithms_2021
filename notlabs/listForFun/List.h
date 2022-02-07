#ifndef ALGORITHMS_2021_LIST_H
#define ALGORITHMS_2021_LIST_H

#include <iostream>

template <class T>class List{

public:

    List();

    void add(const T & value);

    bool isEmpty();

    int size();

    void print();

    T elementAt(int index);

    bool operator== (const List <T>& scr);

    bool operator== (List<T> *scr);

    bool operator!= (const List <T>& scr);

private:

    template <class T>
    struct Node {

        T  _value;
        Node<T>* _previous;
        Node<T>* _next;

        Node(T value, Node<T> *previous = nullptr, Node<T> *next = nullptr) : _value(value), _previous(previous), _next(next) {}

    };

    Node<T>* _root;
};

template <class T>
List<T>::List() : _root(nullptr) {}

template <class T>
void List<T>::add(const T & value){
    auto* next = new Node<T>(value, nullptr, nullptr);
    if(_root == nullptr) _root = next;
    else {
        Node<T>* last = _root;
        while(last->_next != nullptr) last = last->_next;
        last->_next = next;
        next->_previous = last;
    }
}

template <class T>
bool List<T>::isEmpty(){ return (_root == nullptr); }

template <class T>
void List<T>::print(){
    Node<T>* last = _root;
    while(last->_next != nullptr){
        std::cout << last->_value << " ";
        last = last->_next;
    }
    std::cout << last->_value << " ";
}

template <class T>
T List<T>::elementAt(int index) {
    Node<T>* current = _root;
    for (int i = 1; i < index; ++i) {
        current = current->_next;
    }
    return current->_value;
}

template <class T>
int List<T>::size() {
    if(_root == nullptr) return 0;
    int size = 1;
    Node<T>* temp = _root;
    while(temp->_next != nullptr){
        temp = temp->_next;
        size++;
    }
    return size;
}

template <class T>
bool List<T>::operator== (const List <T> & scr)
{
    return _root == scr._root;
}

template <class T>
bool List<T>::operator== (List<T> *scr)
{
    return _root == &scr->_root;
}


template <class T>
bool List<T>::operator!= (const List <T>& scr){ return !(this == scr); }
#endif //ALGORITHMS_2021_LIST_H
