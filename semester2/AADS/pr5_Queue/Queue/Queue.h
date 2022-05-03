//
// Created by ������������� on 22.03.2022.
//

#ifndef ALGORITHMS_2021_QUEUE_H
#define ALGORITHMS_2021_QUEUE_H


template <class T>
class Queue
{
public:
    virtual ~Queue () {}
    virtual void enQueue (const T& e) = 0; // ���������� ��������
    virtual T deQueue () = 0; // �������� � ����������� ��������
    virtual bool isEmpty() = 0; // �������� �� �������
};

#endif //ALGORITHMS_2021_QUEUE_H
