#ifndef CLASS_ARRAY
#define CLASS_ARRAY

#include <iostream>

template <class T>
class Array
{
public:
	Array();
	Array(size_t size);

	Array(const Array<T>& other);
	Array(Array<T>&& other) noexcept;

	~Array();

	Array<T>& operator=(const Array<T>& other);
	Array<T>& operator=(const Array<T>&& other);

	void addElement(const T& newElement);

	void swap(Array& other) noexcept;

	T& operator[] (size_t index) const;

	size_t getSize() const;

	void swapElements(size_t firstIndex, size_t secondIndex);
private:
	size_t size_;
	T* data_;
};

template <class T>
Array<T>::Array() :
	size_(0),
	data_(nullptr)
{}

template <class T>
Array<T>::Array(size_t size) :
	size_(size),
	data_(size_ == 0 ? nullptr : new T[size_])
{}

template <class T>
Array<T>::Array(const Array<T>& other) :
	size_(other.size_),
	data_(size_ == 0 ? nullptr : new T[size_])
{
	for (size_t i = 0; i < size_; ++i) {
		data_[i] = other.data_[i];
	}
}

template <class T>
Array<T>::Array(Array<T>&& other) noexcept :
	size_(other.size_),
	data_(other.data_)
{
	other.size_ = 0;
	other.data_ = nullptr;
}

template <class T>
Array<T>::~Array()
{
	delete[] data_;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		Array<T> temp(other);
		swap(temp);
	}
	return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>&& other)
{
	if (this != &other) {
		swap(other);
	}
	return *this;
}

template<class T>
void Array<T>::addElement(const T& newElement)
{
	Array<T> temp(size_ + 1);
	temp.data_ = new T[temp.size_];
	
	for (size_t i = 0; i < size_; ++i) {
		temp.data_[i] = data_[i];
	}
	temp.data_[size_] = newElement;

	swap(temp);
}

template<typename T>
void Array<T>::swap(Array& other) noexcept
{
	std::swap(data_, other.data_);
	std::swap(size_, other.size_);
}

template<typename T>
T& Array<T>::operator[](size_t index) const
{
	if (index >= size_) {
		throw std::out_of_range("IndexError: list index out of rangee");
	}
	return data_[index];
}

template<typename T>
size_t Array<T>::getSize() const
{
	return size_;
}

template<class T>
void Array<T>::swapElements(size_t firstIndex, size_t secondIndex)
{
	std::swap(data_[firstIndex], data_[secondIndex]);
}

#endif