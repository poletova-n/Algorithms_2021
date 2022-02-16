#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <cassert>

template <class T>
struct Node
{
	Node(T data = T(), Node* nextPtr = nullptr, Node* behindPtr = nullptr) :
		data(data), nextPtr(nextPtr), behindPtr(behindPtr) {}
	T data;
	Node<T>* nextPtr;
	Node<T>* behindPtr;
};


template <class T>
class DoubleList
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	int size;
public:
	DoubleList() :Head(nullptr), Tail(nullptr), size(0) {}
	virtual ~DoubleList();

	bool replaceItem(int itemOld, int itemNew, bool all);
	bool replaceItem(int itemOld, int itemNew);
	Node<T>* replaceNode(Node<T>* x, int item);

	bool deleteItem(const int item, bool all);
	bool deleteItem(const int item);
	void deleteNode(Node<T>* node);

	void insertHead(Node<T>* node);
	void insertTail(Node<T>* otherNode);

	bool deleteTail();
	bool deleteHead();

	void add(DoubleList<T>& list);
	void push_back(T data);

	void swap(DoubleList<T>& other) noexcept;
	void printList();

	int getSize() { return size; }
	Node<T>* getHead() { return Head; }
	Node<T>* getTail() { return Tail; }

	int getSize() const { return size; }
	Node<T>* getHead() const { return Head; }
	Node<T>* getTail() const { return Tail; }

	T& operator[](const T index);
	friend std::ostream& operator << (std::ostream& out, DoubleList<T>& list);
	friend bool operator == (const DoubleList<T>& one, const DoubleList<T>& two);
};

template <class T>
std::ostream& operator << (std::ostream& out, DoubleList<T>& list);
template <class T>
bool operator == (const DoubleList<T>& one, const DoubleList<T>& two);


#endif // DOUBLELIST_H

