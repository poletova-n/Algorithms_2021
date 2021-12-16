#pragma once
#include <iostream>
#include <cstddef>

class String {
private:
    std::size_t size;
    std::size_t capacity;
    char* pointer;
public:
    String();
    String(const char*);
    String(const String*);
    String(int);
    String(String&&) noexcept;
    ~String();

    char* getCString();

    String& insert(std::size_t, const char*);
    String& operator=(const char*);
    String& operator=(String&&) noexcept;
    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
    char& operator[](std::size_t);

    int compare(const String&);
    friend int getSize(const String&);
};





#ifndef ALGORITHMS_2021_STRING_H
#define ALGORITHMS_2021_STRING_H

#endif //ALGORITHMS_2021_STRING_H
