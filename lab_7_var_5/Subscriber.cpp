#include "Subscriber.hpp"
Subscriber::~Subscriber() {
  _surname.clear();
  _name.clear();
  _number.clear();
  _code.clear();
}
Subscriber::Subscriber() {
  _surname = "";
  _name = "";
  _number = "";
  _code = "";
}
Subscriber::Subscriber(Subscriber &s) { *this = s; }
void Subscriber::operator=(Subscriber &s) {
  _surname = s.surname();
  _name = s.name();
  _number = s.number();
  _code = s.code();
}
void Subscriber::surname(String &s) { _surname = s; }
void Subscriber::name(String &s) { _name = s; }
void Subscriber::number(String &s) { _number = s; }
void Subscriber::code(String &s) { _code = s; }
bool Subscriber::check_surname() {
  if (!(_surname[0] >= 'A' && _surname[0] <= 'Z'))
    return false;
  if (_surname.size() < 3 || _surname.size() > 20)
    return false;
  for (char c : _surname)
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-'))
      return false;
  return true;
}
bool Subscriber::check_name() {
  if (_name.size() == 2 && _name[0] >= 'A' && _name[0] <= 'Z' &&
      _name[1] == '.')
    return true;
  return false;
}
bool Subscriber::check_number() {
  if (_number.size() != 16)
    return false;
  if (_number[0] != '+' || _number[2] != '(' || _number[6] != ')' ||
      _number[10] != '-' || _number[13] != '-')
    return false;
  for (std::size_t i = 0; i < _number.size(); i++) {
    if (i == 0 || i == 2 || i == 6 || i == 10 || i == 13)
      continue;
    if (!(_number[i] >= '0' && _number[i] <= '9'))
      return false;
  }
  return true;
}
bool Subscriber::check_code() {
  if (_code.size() != 3)
    return false;
  for (char c : _code)
    if (!(c >= '0' && c <= '9'))
      return false;
  return true;
}
bool Subscriber::check() {
  return check_surname() && check_name() && check_number() && check_code();
}
String &Subscriber::surname() { return _surname; }
String &Subscriber::name() { return _name; }
String &Subscriber::number() { return _number; }
String &Subscriber::code() { return _code; }
void *Subscriber::operator new(std::size_t n) { return malloc(n); }
void Subscriber::operator delete(void *n) { free(n); }
void *Subscriber::operator new[](std::size_t n) { return malloc(n); }
void Subscriber::operator delete[](void *n) { free(n); }
std::ostream &operator<<(std::ostream &os, Subscriber &s) {
  os << s.surname() << ' ' << s.name() << ' ' << s.number() << ' ' << s.code();
  return os;
}
