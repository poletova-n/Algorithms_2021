#include "String.hpp"

char *String::begin() { return &_pointer.front(); }
char *String::end() { return &_pointer.front() + _size; }
String::~String() { _pointer.clear(); }
String::String() {
  _pointer.clear();
  _pointer.resize(_capacity, '\0');
}
String::String(std::size_t len, char c) : String() {
  for (std::size_t i = 0; i < len; i++) {
    _pointer[i] = c;
    _size++;
  }
}
String::String(String &s) : String() {
  for (char c : s)
    this->insert(c);
}
String::String(String &&s) {
  _pointer = s.pointer();
  _size = s.size();
  _capacity = s.capacity();
}
String::String(const char *s) : String() { this->insert(s); }
void String::insert(String &s) {
  for (char c : s)
    this->insert(c);
}
void String::insert(const char *s) {
  for (int i = 0; s[i] != '\0'; i++)
    this->insert(s[i]);
}
void String::insert(const char &s) {
  _pointer[_size] = s;
  _size++;
}
void String::clear() {
  _size = 0;
  _pointer.clear();
}
Vector<char> String::pointer() { return _pointer; }
std::size_t String::size() { return _size; }
std::size_t String::capacity() { return _capacity; }
String String::operator+(String &s) {
  String tmp(*this);
  tmp.insert(s);
  return tmp;
}
String String::operator+(const char *s) {
  String tmp(*this);
  tmp.insert(s);
  return tmp;
}
String String::operator+(const char s) {
  String tmp(*this);
  tmp.insert(s);
  return tmp;
}
void String::operator=(String &s) {
  clear();
  this->insert(s);
  _capacity = s.capacity();
}
void String::operator=(const char *s) {
  clear();
  this->insert(s);
}
void String::operator=(char s) {
  clear();
  this->insert(s);
}
void String::operator+=(String &s) {
  for (char c : s)
    this->insert(c);
  _size = s.size();
  _capacity = s.capacity();
}
void String::operator+=(const char *s) {
  for (int i = 0; i != '\0'; i++) {
    this->insert(s[i]);
  }
}
void String::operator+=(char s) { this->insert(s); }
char &String::operator[](std::size_t i) { return _pointer[i]; }
bool String::operator>(String &s) {
  if (_size > s.size())
    return true;
  if (_size < s.size())
    return false;
  for (std::size_t i = 0; i < _size; i++) {
    if ((*this)[i] > s[i])
      return true;
    if ((*this)[i] < s[i])
      return false;
  }
  return false;
}
bool String::operator<(String &s) {
  if (_size < s.size())
    return true;
  if (_size > s.size())
    return false;
  for (std::size_t i = 0; i < _size; i++) {
    if ((*this)[i] < s[i])
      return true;
    if ((*this)[i] > s[i])
      return false;
  }
  return false;
}
bool String::operator==(String &s) {
  if (_size != s.size())
    return false;
  for (std::size_t i = 0; i < _size; i++)
    if ((*this)[i] != s[i])
      return false;
  return true;
}
bool String::operator!=(String &s) { return !((*this) == s); }
std::istream &operator>>(std::istream &is, String &s) {
  s.clear();
  char c = 0;
  while (is.read(&c, 1)) {
    if (c == ' ' || c == '\n' || c == '\0') {
      if (s.size() == 0) {
        continue;
      } else {
        break;
      }
    }
    s.insert(c);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, String &s) {
  for (char c : s)
    os << c;
  return os;
}
