#pragma once
template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};

