#pragma once
#include<iostream>
#include<string>
#include<iterator>
#include"Stack.h"
#include"Exception.h"



template <class T>
class StackArray : public Stack<T> {
private:
	T* array_; // массив элементов стека: !!! array_[0] – не используется, top_ от 1 до size_ 
	size_t top_; // вершина стека, элемент занесенный в стек последним
	size_t size_; // размер стека
	void swap(StackArray<T>& src);
public:
	StackArray<T>(size_t size = std::numeric_limits<int>::max()) :size_(size), top_(0) // size задает размер стека "по умолчанию"
	{// !!! array_[0] – не используется, top_ от 1 до size_
		try {
			array_ = new T[size + 1]; // пытаемся заказать память под элементы стека...
		}
		catch (...) { // если что-то случилось (например, размер слишком большой
			WrongStackSize e; // или отрицательный) - возникает исключительная ситуация
			std::cout << e.what() << "\n";
			exit(1);
		}
	}

	
	//конструктор копирования - создание копии имеющегося списка
	StackArray(const StackArray<T>& src) {
		size_ = src.size_;
		array_ = new T[size_];
		for (int i = 1; 1 <= size_; i++) {
			push(src.array_[i]);
		}
	}
	//конструктор перемещения
	StackArray(StackArray<T>&& src) {
		array_ = src.array_;
		size_ = src.size_;
		top_ = src.top_;

		src.array_ = nullptr;
		src.size_ = 0;
		src.top_ = 0;
	};
	//оператор присваивания(копирущее присваивание)
	StackArray& operator=(const StackArray<T>& src); 
	//оператор перемещающего присваивания
	StackArray& operator=(StackArray<T>&& src);
	//диструктор
	virtual ~StackArray() { delete[] array_; top_ = 0; size_ = 0; }
	void push(const T& e);
	T pop();
	T top();
	bool isEmpty() { return top_ == 0; };
	size_t getLenght() { return top_; };
	void print(std::ostream& stream) const;

};

template <class T>
void StackArray<T> ::swap(StackArray<T>& src)
{
	std::swap(array_, src.array_); // (this->array_, src.array_) 
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}

template <class T>
void StackArray<T>::push(const T& e)
{
	try {
		if (top_ == size_) { // нет места для нового элемента
			//StackOverflow ex;
			throw StackOverflow();
		}
		array_[++top_] = e; // занесение элемента в стек
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

template <class T>
T StackArray<T>::pop()
{
	try {
		if (isEmpty()) { // (top_ == 0) 
			StackOverflow ex;// стек пуст
			throw StackUnderflow();
		}
		return array_[top_--]; // Элемент физически остается в стеке, но больше "не доступен"
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

template <class T>
T StackArray<T>::top() { return array_[top_]; }

template <class T>
void StackArray<T>::print(std::ostream& stream) const {
	try {
		for (int i = 0; i != top_; i++) {
			std::cout << array_[i + 1] << " ";
}
	}
	catch (...) {
		throw WrongStackSize;
	}
}

template <class T>
StackArray<T>& StackArray<T>::operator=(const StackArray<T>& src){
	if (this == &src)
		return *this;
	if (array_)
		delete[]array_;
	size_ = src.size_;
	array_ = new T[size_];
	for (int i = 1; i <= size_; i++)
		push(src.array_[i]);
	return *this;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src) {
	if (&src == this)
		return *this;
	if (array_)
		delete[]array_;
	array_ = src.array_;
	top_ = src.top_;
	size_ = src.size_;
	src.array_ = nullptr;
	src.top_ = 0;
	src.size_ = 0;
	return *this;
}