#include <iostream>
//
// Created by reenie on 04.12.2021.
//

class String {
private:
	char* _raw_string;
	size_t length;
public:
	String () {
		this->_raw_string = new char;
		*(this->_raw_string) = '\0';
		this->length = 0;
	}

	String (char* str) {
		size_t i = 0;
		while (str[i] != '\0') { // поиск длины строки
			i++;
		}

		this->_raw_string = new char[i]; // выделение памяти на строку
		for (size_t j = 0; j < i; j++) {
			this->_raw_string[j] = str[j]; // поэлементное копирование
		}
		this->_raw_string[i] = '\0'; // терминальный символ в конце

		this->length = i-1; // запись длины
	}

	String (const String& str) {
		this->_raw_string = new char[str.length];
		for (size_t i = 0; i < str.length; i++) {
			this->_raw_string[i] = str._raw_string[i];
		}
		this->_raw_string[str.length] = '\0';
		this->length = str.length;
	}

	~String () {
		delete[] this->_raw_string;
	}

	size_t get_length () {
		return this->length;
	}

	char& operator[] (size_t index) {
		if (index < this->length) {
			return this->_raw_string[index];
		} else {
			throw std::exception();
		}
	}

	int32_t compare (String& str) {
		size_t i = 0;
		while ((i < this->length) && (i < str.length)) {
			if ((*this)[i] < str[i]) {
				return -1;
			} else if ((*this)[i] > str[i]) {
				return  1;
			} else {
				i++;
			}
		}
		if (this->length < str.length) {
			return -1;
		} else if (this->length > str.length) {
			return  1;
		} else {
			return 0;
		}
	}
};

#ifndef ALGORITHMS_2021_STRING_H
#define ALGORITHMS_2021_STRING_H

#endif //ALGORITHMS_2021_STRING_H
