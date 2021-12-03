#include <iostream>
#include <fstream>
#include "String.h"

String::String() {
    this->_length = 0;
    this->_charArray = new char[this->_length];
}

String::String(const char input[]) {
    for (int i = 0; i < 7; ++i) {
        if (input[i] == '\0') {
            this->_length = i;
        }
    }
    this->_charArray = new char[this->_length];
    for (int i = 0; i < 7; ++i) {
        if (input[i] == '\0') {
            this->_charArray[i] = input[i];
        }
    }
}

String::String(const String& input) {
    this->_charArray = input._charArray;
    this->_length = input._length;
}

String::String(String&& input) noexcept {
    this->_charArray = input._charArray;
    this->_length = input._length;
    input._charArray = nullptr;
    input._length = 0;
}

String& String::operator=(const String& input) {
    if (this != &input)
    {
        this->_charArray = input._charArray;
        this->_length = input._length;
    }
    return *this;
}

String& String::operator=(String&& input)  noexcept {
    if (this != &input)
    {
        delete[] _charArray;

        this->_charArray = input._charArray;
        this->_length = input._length;
        input._charArray = nullptr;
        input._length = 0;
    }
    return *this;
}

String& String::operator+=(char& input) {

    int newLenght = this->_length + 1;
    char* array = new char[this->_length + 1];

    for (int i = 0; i < this->_length; ++i) {
        array[i] = this->_charArray[i];
    }

    array[this->_length] = input;

    delete this->_charArray;

    this->_charArray = array;
    this->_length = newLenght;

    return *this;
}

int String::compare(const String& input) const {

    int min = std::min(input._length, this->_length);

    for (int i = 0; i < min; ++i) {
        if (this->at(i) > input.at(i)) { return 1; }
        else if (this->at(i) < input.at(i)) { return 0; }
    }

    if (this->_length > input._length) { return 0; }
    if (this->_length < input._length) { return 1; }

    return 2;
}

std::fstream& operator>>(std::fstream& input, String& string) {
    input >> std::noskipws;

    string._length = 0;
    char current = 0;

    input >> current;
    while (current == ' ' || current == 10) {
        input >> current;
    }
    while (current != ' ' && current != 10 && !input.eof()) {
        string += current;
        input >> current;
    }

    return input;
}

std::fstream& operator<<(std::fstream& output, String& string) {

    for (int i = 0; i < string._length; ++i) {
        output << string._charArray[i];
    }

    return output;
}

void String::toString() {
    for (int i = 0; i < this->_length; ++i) {
        std::cout << this->_charArray[i];
    }
}

char* String::getCharArray() const {
    return _charArray;
}

int String::length() const {
    return _length;
}

void String::setCharArray(char* charArray) {
    _charArray = charArray;
}

void String::setLength(int length) {
    _length = length;
}

char String::at(int index) const {
    return this->_charArray[index];
}

std::istream& operator>>(std::istream& input, String& string) {
    input >> std::noskipws;

    string._length = 0;
    char current = 0;

    input >> current;
    while (current == ' ' || current == 10) {
        input >> current;
    }
    while (current != ' ' && current != 10 && !input.eof()) {
        string += current;
        input >> current;
    }
    std::cout << "1";

    return input;;
}

std::ostream& operator<<(std::ostream& output, String& string) {
    for (int i = 0; i < string._length; ++i) {
        output << string._charArray[i];
    }
    return output;
}