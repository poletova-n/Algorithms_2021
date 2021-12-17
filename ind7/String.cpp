#include "String.h"

#include <iostream>
#include <cmath>

String::String() :
	size_(0),
	capacity_(size_ + 1),
	pointer_(new char[capacity_])
{}

String::String(const char* str)
{
	size_ = 0;
	while (str[size_] != '\0') {
		++size_;
	}
	capacity_ = size_ + 1;
	pointer_ = new char[capacity_];
	
	for (unsigned int i = 0; i < capacity_; ++i) {
		pointer_[i] = str[i];
	}
}

String::String(const String& source) :
	size_(source.size_),
	capacity_(size_ + 1),
	pointer_(new char[capacity_])
{
	strcpy_s(pointer_, capacity_, source.pointer_);
}

String::String(String&& source) noexcept :
	pointer_(source.pointer_),
	size_(source.size_),
	capacity_(source.capacity_)
{
	source.pointer_ = nullptr;
	source.size_ = 0;
	source.capacity_ = 0;
}

String::~String()
{
	delete[] pointer_;
}

String& String::operator=(const String& source)
{
	if (this != &source) 
	{
		String temp(source);
		swap(temp);
	}
	return *this;
}

String& String::operator=(String&& source) noexcept
{
	if (this != &source)
	{
		swap(source);
	}
	return *this;
}

String& String::operator+=(const char& extraChar)
{
	String temp;
	temp.size_ = size_ + 1;
	temp.capacity_ = capacity_ + 1;
	temp.pointer_ = new char[temp.capacity_];
	if (capacity_ > 1) {
		strcpy_s(temp.pointer_, capacity_, pointer_);
	}
	temp.pointer_[temp.capacity_ - 2] = extraChar;
	temp.pointer_[temp.capacity_ - 1] = '\0';

	swap(temp);

	return *this;
}

int String::compare(const String& str) const
{
	for (unsigned int i = 0; i < (size_ < str.size_ ? size_ : str.size_); i++) {
		if (pointer_[i] > str[i]) {
			return 1;
		}
		else if (pointer_[i] < str[i]) {
			return -1;
		}
	}

	if (size_ < str.size_) {
		return -1;
	}
	else if (size_ > str.size_) {
		return 1;
	}


	return 0;
}

char& String::operator[](const size_t& index) const
{
	if (index >= size_) {
		throw std::out_of_range("IndexError: String index out of range");
	}
	return pointer_[index];
}

size_t String::size() const
{
	return size_;
}

void String::swap(String& other)
{
	std::swap(pointer_, other.pointer_);
	std::swap(size_, other.size_);
	std::swap(capacity_, other.capacity_);
}

String::operator const char* () const
{
	return pointer_;
}

std::istream& getline(std::istream& in, String& destination)
{
	destination = String();
	bool isSomethingIn = false;
	char ch = 1;
	while (ch != '\n' && ch != '\0' && (ch = in.get()) != EOF)
	{
		isSomethingIn = true;
		if (ch == '\n')
		{
			//destination += '\0';
			break;
		}
		else {
			destination += ch;
		}
	}

	if (!isSomethingIn) {
		destination = " ";
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.pointer_;
	return out;
}
