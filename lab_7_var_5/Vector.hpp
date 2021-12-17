#pragma once
#include <iostream>
template <class T> class Vector {
private:
  std::size_t _size = 0;
  std::size_t _capacity = 1024;
  T *_pointer = nullptr;

public:
  ~Vector() {
    if (_pointer != nullptr)
      delete[] _pointer;
  }
  Vector() {
    if (_pointer == nullptr)
      _pointer = new T[_capacity];
  }
  Vector(Vector &v) : Vector() { *this = v; }
  Vector(Vector &&v) { this = v; }
  Vector(std::size_t len, const T &obj) : Vector() {
    for (std::size_t i = 0; i < len; i++)
      _pointer[i] = obj;
    _size = len;
  }
  Vector(const T &obj) : Vector() {
    _size = 1;
    _pointer[0] = obj;
  }
  Vector(std::initializer_list<T> init) : Vector() {
    for (auto i : init)
      _pointer[_size++] = i;
  }
  void operator=(Vector &&v) {
    if (_pointer != nullptr)
      delete[] _pointer;
    _pointer = v.pointer();
    _size = v.size();
    _capacity = v.capacity();
  }
  void operator=(Vector &v) {
    for (std::size_t i = 0; i < v.size(); i++)
      _pointer[i] = v[i];
    _size = v.size();
    _capacity = v.capacity();
  }
  void operator=(std::initializer_list<T> init) {
    std::size_t index = 0;
    for (auto i : init)
      _pointer[index++] = i;
    _size = index;
  }
  void operator=(const T &obj) {
    _size = 1;
    _pointer[0] = obj;
  }
  T &operator[](std::size_t i) { return _pointer[i]; }
  std::size_t size() { return _size; }
  void clear() { _size = 0; }
  std::size_t capacity() { return _capacity; }
  T *pointer() { return _pointer; }
  T *begin() { return _pointer; }
  T *end() { return _pointer + _size; }
  void resize(std::size_t n, const T &v) {
    for (std::size_t i = 0; i > n; i++)
      _pointer[i] = v;
  }
  T &front() { return _pointer[0]; }
};
