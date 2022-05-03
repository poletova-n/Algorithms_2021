//
// Created by Администратор on 22.03.2022.
//

#ifndef ALGORITHMS_2021_QUEUE_H
#define ALGORITHMS_2021_QUEUE_H


template <class T>
class Queue
{
public:
    virtual ~Queue () {}
    virtual void enQueue (const T& e) = 0; // Добавление элемента
    virtual T deQueue () = 0; // Удаление и возвращение элемента
    virtual bool isEmpty() = 0; // Проверка на пустоту
};

#endif //ALGORITHMS_2021_QUEUE_H
