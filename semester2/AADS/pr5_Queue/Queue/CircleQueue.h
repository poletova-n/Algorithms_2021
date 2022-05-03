//
// Created by Администратор on 22.03.2022.
//
#ifndef ALGORITHMS_2021_CIRCLEQUEUE_H
#define ALGORITHMS_2021_CIRCLEQUEUE_H

#include <iostream>
#include "Queue.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"
#include "QueueWrongSize.h"


template <class T>
class CircleQueue : public Queue<T>{
private:

    T* array_;

    int head_;

    int tail_;

    int size_;

public:

    explicit CircleQueue(int size = 20) : size_(size), head_(-1), tail_(-1){
        try {
            try {
                array_ = new T[size];
            } catch (std::exception &e) {
                throw QueueWrongSize();
            }
        }
        catch (std::exception &e) {
            system("cls");
            std::cerr << std::endl << e.what() << std::endl;
            exit(1);
        }
    };

    ~CircleQueue () {
        delete array_;
    }

    void enQueue (const T& e){
        try {
            if(isFull()) throw QueueOverflow();
            tail_ = (tail_+1)%size_;
            array_[tail_] = e;
        }
        catch (std::exception &e) {
            //system("cls");
            std::cerr << std::endl << e.what() << std::endl;
            exit(1);
        }
    };

    T deQueue (){
        try{
            if(isEmpty()) throw QueueUnderflow();
            head_ = (head_+1)%size_;
            T ans = array_[head_];
            if(tail_ == head_){
                tail_ = -1;
                head_ = -1;
            }
            return ans;
        }
        catch (std::exception &e) {
            system("cls");
            std::cerr << std::endl << e.what() << std::endl;
            exit(1);
        }
    }

    bool isEmpty(){
        return head_ == -1 && tail_ == -1;
    };

    bool isFull(){
        if(head_ == -1 && tail_ == -1)  return false;
        return head_ == tail_ + 1 || (head_ == -1 && tail_ == size_ - 1);
    }

    void print(){
        for (int i = 0; i < size_; ++i) {
            std::cout << array_[i] << " ";
        }
        std::cout << std::endl;
    }

    int getSize(){
        return abs(tail_ - head_);
    }
};


#endif //ALGORITHMS_2021_CIRCLEQUEUE_H