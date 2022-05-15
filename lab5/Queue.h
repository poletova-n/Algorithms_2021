//
// Created by Foko on 15.05.2022.
//

#ifndef ONE_WAY_LIST_QUEUE_H
#define ONE_WAY_LIST_QUEUE_H


template <class T> class Queue {
public:
    virtual ~ Queue () {}
    virtual void enQueue (const T& e) = 0; // Добавление элемента
    virtual T deQueue () = 0; // Удаление и возвращение элемента
    virtual bool isEmpty() = 0; // Проверка на пустоту
};


#endif //ONE_WAY_LIST_QUEUE_H
