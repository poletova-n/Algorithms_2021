#pragma once
#include "Vector.hpp"
#include <iostream>
// #include <vector>
// #define Vector std::vector

class String {
private:
  std::size_t _capacity = 1024;
  std::size_t _size = 0;
  Vector<char> _pointer;

public:
  char *begin();
  char *end();
  ~String();
  String();
  String(std::size_t len, char c);
  String(String &s);
  String(String &&s);
  String(const char *s);
  void insert(String &s);
  void insert(const char *s);
  void insert(const char &s);
  void clear();
  Vector<char> pointer();
  std::size_t size();
  std::size_t capacity();
  String operator+(String &s);
  String operator+(const char *s);
  String operator+(const char s);
  void operator=(String &s);
  void operator=(const char *s);
  void operator=(char s);
  void operator+=(String &s);
  void operator+=(const char *s);
  void operator+=(char s);
  char &operator[](std::size_t i);
  bool operator>(String &s);
  bool operator<(String &s);
  bool operator==(String &s);
  bool operator!=(String &s);
  friend std::istream &operator>>(std::istream &, String &);
  friend std::ostream &operator<<(std::ostream &, String &);
};
