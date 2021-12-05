#include <iostream>
//
// Created by reenie on 04.12.2021.
//

class String {
private:
	char* _raw_string;
	size_t length;
public:
	String (); // дефолтный конструктор инициализации

	explicit String (const char* str); // конструктор инициализации

	String (const String& str); // конструктор копирования

	String (String&& str) noexcept; // конструктор перемещения

	~String (); // деструктор

	size_t get_length () {
		return this->length;
	}

	char& operator[](size_t index); // оператор доступа по индексу
	String& operator=(const String& str); // оператор присваивания копированием
	String& operator=(String&& str) noexcept; // оператор присваивания перемещением

	int32_t compare (String& str);

	friend std::ostream& operator<< (std::ostream& out, String& str);
};

#ifndef ALGORITHMS_2021_STRING_H
#define ALGORITHMS_2021_STRING_H

#endif //ALGORITHMS_2021_STRING_H

#include "string.cpp"