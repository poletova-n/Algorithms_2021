#include "String.hpp"
#include <iostream>
// #include <string>
// #define String std::string
class Subscriber {
private:
  String _surname;
  String _name;
  String _number;
  String _code;

public:
  ~Subscriber();
  Subscriber();
  Subscriber(Subscriber &s);
  Subscriber(std::initializer_list<String>);
  void operator=(Subscriber &s);
  void surname(String &s);
  void name(String &s);
  void number(String &s);
  void code(String &s);
  bool check_surname();
  bool check_name();
  bool check_number();
  bool check_code();
  bool check();
  String &surname();
  String &name();
  String &number();
  String &code();
  void *operator new(std::size_t n);
  void operator delete(void *n);
  void *operator new[](std::size_t n);
  void operator delete[](void *n);
  friend std::ostream &operator<<(std::ostream &, Subscriber &);
};
