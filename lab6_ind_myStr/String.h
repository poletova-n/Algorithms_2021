#ifndef MAIN_CPP_STRING_H
#define MAIN_CPP_STRING_H

#include <ostream>
#include <cstring>
class String {
public:
    String();
    String(const char* string); //Конструктор из си строки
    String(const String& string); //Конструктор копирования
    String(String&& string); //Конструктор перемещения

    int size() { return length_; }
    int length() { return length_; }

    char get(const int index) const { return string_[index]; }

    String& operator=(const String& string); //Присваивание копированием
    String& operator=(String&& string); //Присваивание перемещением
    String& operator+=(const String& string);
    String& operator+=(const char& ch);
    bool operator==(const String& ch);
    friend std::ostream& operator<< (std::ostream& out, const String& string);
    std::ostream& operator<< (std::ostream& out);
    bool operator>(const String& str);
    char& operator[](const int index);
private:
    void resize(int size);
    char* string_;
    int capacity_;
    int length_;

};

#endif //MAIN_CPP_STRING_H
