#pragma once
#include "Queue.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"
#include "QueueWrongSize.h"

template <class T>
class CircleQueue : public Queue<T>
{
private:
	int m_size;
	T* m_array;
	int m_front, m_rear;
public:
	CircleQueue() : m_size(10), m_array(new T[10]), m_rear(-1), m_front(-1) {}
	CircleQueue(int size) : m_rear(-1), m_front(-1)
	{
		if (size < 1)
			throw QueueWrongSize();

		m_size = size;
		m_array = new T[m_size];
	}
	virtual ~CircleQueue()
	{
		delete m_array;
		m_array = nullptr;
		m_size = 0;
		m_rear = -1;
		m_front = -1;
	}
	virtual void enQueue(const T& e)
	{
		if (isFull())
			throw QueueOverflow();

		if (m_front == -1)
			m_front = 0;

		m_rear = (m_rear + 1) % m_size;
		m_array[m_rear] = e;
	}
	virtual T deQueue()
	{
		if (isEmpty())
			throw QueueUnderflow();

		T element;
		element = m_array[m_front];
		if (m_front == m_rear)
		{
			m_front = -1;
			m_rear = -1;
		}
		else
			m_front = (m_front + 1) % m_size;

		return element;

	}
	virtual bool isEmpty()
	{
		if (m_front == -1)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (m_front == m_rear + 1 || (m_front == 0 && m_rear == m_size - 1))
			return true;
		else
			return false;
	}
};
#pragma once
