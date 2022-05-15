//
// Created by Foko on 15.05.2022.
//

#ifndef ONE_WAY_LIST_CIRCLEQUEUE_H
#define ONE_WAY_LIST_CIRCLEQUEUE_H

#include "Queue.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"
#include "WrongSizeQueue.h"
#include <vector>
#include <iterator>
#include <iostream>

template <typename T>
class CircleQueue: public Queue<T> {
private:
    int front = -1;
    int rear = -1;
    std::vector<T> storage{};
public:
    explicit CircleQueue (int);

    void enQueue (const T&) override;
    T deQueue () override;
    bool isEmpty() override;
    bool isFull();

   /*template <typename U> friend std::ostream& operator<<(std::ostream& out, CircleQueue<U>& queue) {
        std::ostream_iterator<T> out_iterator(out, ", ");
        std::copy(queue.storage.begin(), queue.storage.end(), out_iterator);
        return out;
    }*/
};

#endif //ONE_WAY_LIST_CIRCLEQUEUE_H
