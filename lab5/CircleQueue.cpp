//
// Created by Foko on 15.05.2022.
//

#include "CircleQueue.h"
#include "BinarySearchTree.h"


template <typename T>
CircleQueue<T>::CircleQueue(int n) {
    if (n <= 0) {
        throw WrongSizeQueue();
    } else {
        storage = std::vector<T>(n);
    }
}

template<typename T>
void CircleQueue<T>::enQueue(const T & element) {
    if(isFull()){
        throw QueueOverflow();
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % storage.size();
        storage[rear] = element;
    }
}

template<typename T>
T CircleQueue<T>::deQueue() {
    T element;
    if(isEmpty()){
        throw QueueUnderflow();
    } else {
        element = storage[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front+1) % storage.size();
        }
        return element;
    }
}

template<typename T>
bool CircleQueue<T>::isEmpty() {
    return front == -1;
}

template<typename T>
bool CircleQueue<T>::isFull() {
    if (front == 0 && rear == storage.size() - 1) {
        return true;
    }
    if (front == rear + 1) {
        return true;
    }
    return false;
}

template class CircleQueue<BinarySearchTree<int>::Node*>;
template class CircleQueue<int>;