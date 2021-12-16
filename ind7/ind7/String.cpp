#include "String.h"
#include <iostream>

String::String()
{
    size = 0;
    capacity = 0;
    pointer = nullptr;
}

String::String(const char* str)
{
    capacity = 0;
    size = 0;
    int i = 0;
    while (true)
    {
        if (str[i] == '\0')
        {
            size = ++i;
            break;
        }
        i++;
    }
    capacity = size * sizeof(char);
    pointer = new char[size];
    for (i = 0; i < size-1; i++)
    {
        pointer[i] = str[i];
    }
    pointer[size-1] = '\0';
}

String::String(const String* str) {
    capacity = 0;
    size = 0;
    int i = 0;
    while (true) {
        if (str->pointer[i] == '\0') {
            size = ++i;
            break;
        }
        i++;
    }
    capacity = size * sizeof(char);
    pointer = new char[size];
    for (i = 0; i < size - 1; i++) {
        pointer[i] = str->pointer[i];
    }
    pointer[size - 1] = '\0';
}

String::String(int s) {
    size = s;
    pointer = new char[size];
    capacity = size * sizeof(char);
}

String::String(String&& str) noexcept: size(str.size), capacity(str.capacity), pointer(str.pointer) {
    str.capacity = 0;
    str.size = 0;
    pointer = nullptr;
}

String::~String() {
    if (pointer != nullptr)
    {
        delete[] pointer;
        pointer = nullptr;
    }
}

char* String::getCString() {
    return pointer;
}

String& String::operator=(const char* str) {
    *pointer = *str;
    int i = 0;
    while (true) {
        if (str[i] == '\0') {
            size = i;
            capacity = size * sizeof(char);
            break;
        }
        i++;
    }
    return *this;
}

String& String::operator=(String&& str) noexcept {
    size = str.size;
    capacity = str.capacity;
    pointer = str.pointer;

    str.pointer = nullptr;
    str.size = 0;
    str.capacity = 0;

    return *this;
}

std::istream& operator>>(std::istream& in, String& str) {
    in.peek();
    unsigned int size = in.rdbuf()->in_avail();
    String buf(size);
    in.getline(buf.pointer, size);
    str = &buf;
    buf.pointer = nullptr;
    return in;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.pointer;
    return os;
}

char& String::operator[](std::size_t pos) {
    if (pos > size)
    {
        throw "Ошибка! Неверный индекс.\n";
    }
    return *(pointer + pos);
}

String& String::insert(std::size_t pos, const char* chr) {
    if (pos > (size - 1)) {
        std::cout << "Ошибка! Неверная позиция вставки.\n";
    }
    else {
        pointer[pos] = *chr;
    }
    return *this;
}

int String::compare(const String& str) {
    if (size > str.size)return 1;
    if (size < str.size)return -1;

    for(int i = 0; i < size; i++) {
        if (pointer[i] > str.pointer[i])return 1;
        if (pointer[i] < str.pointer[i])return -1;
        i++;
    }
    return 0;
}

int getSize(const String& str) {
    return str.size;
}
