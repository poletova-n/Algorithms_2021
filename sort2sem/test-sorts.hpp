#ifndef TEST_SORTS_HPP
#define TEST_SORTS_HPP

#include "shell-sort.hpp"
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>

void testRandom();

template<typename T>
void initializeRandom(
  T* array, const size_t SIZE, const size_t BITNESS = 1000U);

template<typename T>
void printResults(T* array, const size_t size);

template<typename T>
void test(T* array, const size_t SIZE, void (*sort)(T* array, const size_t SIZE))
{
  auto BEGIN = std::chrono::high_resolution_clock::now();
  sort(array, SIZE);
  auto END = std::chrono::high_resolution_clock::now();
  std::chrono::duration<long double> RESULT = END - BEGIN;
  std::cout << "Size of Array: " << SIZE << "\n";
  std::cout << std::fixed << "Time of sort: " << RESULT.count() <<"\n";
  std::cout << "Count of iterations: " << count << "\n";
}
#endif
