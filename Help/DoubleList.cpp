#include "DoubleList.h"
#include "DoubleList.h"
#include <iostream>
#include <cassert>

template<class T>
std::ostream& operator << (std::ostream& out, DoubleList<T>& list) {
	Node<T>* CurrentPtr = list.getHead();
	if (CurrentPtr == nullptr) {
		out << "Список пуст!" << std::endl;
		return out;
	}

	while (CurrentPtr->nextPtr != nullptr) {
		out << CurrentPtr->data << " ";
		CurrentPtr = CurrentPtr->nextPtr;
	}
	out << CurrentPtr->data << std::endl;
	return out;
}

template<class T>
bool operator == (const DoubleList<T>& one, const DoubleList<T>& two) {
	if (&one == &two) return true;
	if (one.getSize() != two.getSize()) return false;

	Node<T>* CurrentPtrOne = one.getHead();
	Node<T>* CurrentPtrTwo = two.getHead();
	while ((CurrentPtrOne != nullptr) and (CurrentPtrTwo != nullptr)) {
		if (CurrentPtrOne->data != CurrentPtrTwo->data) return false;
		CurrentPtrOne = CurrentPtrOne->nextPtr;
		CurrentPtrTwo = CurrentPtrTwo->nextPtr;
	}

	return true;
}


template<class T>
DoubleList<T>::~DoubleList() {
	while (Head) {
		Tail = Head->nextPtr;
		delete Head;
		Head = Tail;
		size--;
	}
}

template<class T>
void DoubleList<T>::swap(DoubleList<T>& other) noexcept {
	std::swap(Head, other.Head);
	std::swap(Tail, other.Tail);
	std::swap(size, other.size);
}

template<class T>
Node<T>* DoubleList<T>::replaceNode(Node<T>* x, int item) {
	if (x == nullptr) return x;
	x->data = item;
	return x;
}


template<class T>
bool DoubleList<T>::replaceItem(int itemOld, int itemNew) {
	if (Head == nullptr) return false;
	int cntReplace = 0;
	Node<T>* CurrentPtr = Head;
	while (CurrentPtr != nullptr) {
		if (CurrentPtr->data == itemOld) {
			CurrentPtr->data = itemNew;
			cntReplace++;
		}
		CurrentPtr = CurrentPtr->nextPtr;
	}
	return (cntReplace > 0) ? true : false;
}

template<class T>
bool DoubleList<T>::replaceItem(int itemOld, int itemNew, bool all) {
	Node<T>* CurrentPtr = Head;
	if (CurrentPtr == nullptr) return false;

	if (all) {
		while (CurrentPtr != nullptr) {
			if (CurrentPtr->data == itemOld) {
				CurrentPtr->data = itemNew;
			}
			CurrentPtr = CurrentPtr->nextPtr;
		}
		return true;
	}
	else {
		while (CurrentPtr != nullptr) {
			if (CurrentPtr->data == itemOld) {
				CurrentPtr->data = itemNew;
				break;
			}
			CurrentPtr = CurrentPtr->nextPtr;
		}
		return true;
	}
}

template<class T>
void DoubleList<T>::add(DoubleList<T>& list) {
	if (list.size == 0) {
		std::cout << "Нечего добавлять!" << std::endl;
		return;
	}

	if (list.size == 1) {
		push_back(list.Head->data);
		list.size = 0;
		size++;
		delete list.Head;
		list.Head = nullptr;
		return;
	}

	if (size == 0) {
		swap(list);
		return;
	}

	if (size == 1) {
		Node<T>* newPtr = new Node<T>(Head->data);
		int cntTemp = list.size;
		list.insertHead(newPtr);
		T dataTemp = list.Tail->data;

		swap(list);
		push_back(dataTemp);
		size = cntTemp + 1;
		delete list.Head;
		list.Head = nullptr;
		list.Tail = nullptr;
		list.size = 0;
		return;
	}


	Node<T>* newPtr = new Node<T>(Tail->data);
	Tail->behindPtr->nextPtr = newPtr;
	newPtr->behindPtr = Tail->behindPtr;
	delete Tail;
	Tail = nullptr;

	Node<T>* newPtr2 = new Node<T>(list.Head->data);
	list.Head->nextPtr->behindPtr = newPtr2;
	newPtr2->nextPtr = list.Head->nextPtr;
	delete list.Head;
	list.Head = nullptr;

	newPtr->nextPtr = newPtr2;
	newPtr2->behindPtr = newPtr;

	push_back(list.Tail->data);
	delete list.Tail;
	list.Tail = nullptr;
	size += list.size;
	list.size = 0;

}


template<class T>
void DoubleList<T>::deleteNode(Node<T>* node) {
	if (node == nullptr) {
		std::cout << "Пустой элемент!";
		return;
	}

	if (node->behindPtr != nullptr) {
		node->behindPtr->nextPtr = node->nextPtr;
	}
	else {
		Head = node->nextPtr;
	}

	if (node->nextPtr != nullptr) {
		node->nextPtr->behindPtr = node->behindPtr;
	}
	else {
		Tail = node->behindPtr;
	}
	delete node;
	size--;
}

template<class T>
bool DoubleList<T>::deleteItem(const int item) {
	if (Head == nullptr) return false;
	int cntDel = 0;
	Node<T>* CurrentPtr = Head;

	while (CurrentPtr != nullptr) {
		if (CurrentPtr->data == item) {
			if ((CurrentPtr == Head) or (CurrentPtr == Tail)) {
				deleteNode(CurrentPtr);
				cntDel++;
				CurrentPtr = Head;
				continue;
			}
			else {
				deleteNode(CurrentPtr);
				cntDel++;
			}
		}
		CurrentPtr = CurrentPtr->nextPtr;
	}
	return (cntDel > 0) ? true : false;
}

template<class T>
bool DoubleList<T>::deleteItem(const int item, bool all) {
	Node<T>* CurrentPtr = Head;
	if (CurrentPtr == nullptr) return false;

	if (all) {
		while (CurrentPtr != nullptr) {
			CurrentPtr->data = item;
			CurrentPtr = CurrentPtr->nextPtr;
		}
		return true;
	}
	else {
		CurrentPtr->data = item;
		return true;
	}
}


template<class T>
void DoubleList<T>::push_back(T data) {
	if (Head == nullptr) {
		Head = new Node<T>(data);
		Tail = Head;
	}
	else {
		Node<T>* CurrentPtr = Head;
		while (CurrentPtr->nextPtr != nullptr) {
			CurrentPtr = CurrentPtr->nextPtr;
		}
		CurrentPtr->nextPtr = new Node<T>(data);
		Tail = CurrentPtr->nextPtr;
		CurrentPtr->nextPtr->behindPtr = CurrentPtr;
	}
	size++;
}


template<class T>
void DoubleList<T>::insertHead(Node<T>* node) {
	node->nextPtr = Head;
	if (Head != nullptr) {
		Head->behindPtr = node;
	}
	else {
		Tail = node;
	}
	Head = node;
	size++;
}

template<class T>
void DoubleList<T>::insertTail(Node<T>* otherNode) {
	otherNode->behindPtr = Tail;
	if (Head == nullptr) {
		Head = otherNode;
	}
	else {
		Tail->nextPtr = otherNode;
	}
	Tail = otherNode;
	Tail->nextPtr = nullptr;
	size++;
}

template<class T>
bool DoubleList<T>::deleteTail() {
	if (Head == nullptr) return false;
	if (size == 1) {
		delete Tail;
		Head = nullptr;
		Tail = nullptr;
		size--;
		return true;
	}

	Node<T>* temp = Tail;
	Tail = Tail->behindPtr;
	delete temp;
	Tail->nextPtr = nullptr;
	size--;
	return true;
}

template<class T>
bool DoubleList<T>::deleteHead() {
	if (Head == nullptr) return false;
	if (size == 1) {
		delete Head;
		Head = nullptr;
		Tail = nullptr;
		size--;
		return true;
	}
	Node<T>* temp = Head;
	Head = Head->nextPtr;
	delete temp;
	Head->behindPtr = nullptr;
	size--;
	return true;
}

template<class T>
void DoubleList<T>::printList() {
	Node<T>* CurrentPtr = Head;
	while (CurrentPtr->nextPtr != nullptr) {
		std::cout << CurrentPtr->data << " ";
		CurrentPtr = CurrentPtr->nextPtr;
	}
	std::cout << CurrentPtr->data;
}



template<class T>
T& DoubleList<T>::operator[](const T index) {
	assert((index < size) and (index >= 0));
	Node<T>* currentPtr = Head;
	int cnt = 0;
	while (currentPtr->nextPtr != nullptr) {
		if (cnt == index) return currentPtr->data;
		currentPtr = currentPtr->nextPtr;
		cnt++;
	}
}



