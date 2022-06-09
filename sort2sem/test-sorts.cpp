#include "test-sorts.hpp"

template<typename T>
void initializeRandom(
  T* array, const size_t SIZE, const size_t BITNESS)
{
  srand(time(0));
  for (size_t i = 0; i < SIZE; i++)
  {
    array[i] = rand() % BITNESS + 1;
  }
}

template<typename T>
void printResults(T* array, const size_t size)
{
  T* first = new T[size];
  T* second = new T[size];
  std::memcpy(first, array, size);
  std::memcpy(second, array, size);
  std::cout << "\nSHELL\n\n";
  test(array, size, sortShellGaps);
  std::cout << "\nHIBBARD\n\n";
  test(first, size, sortHibbardGaps);
  std::cout << "\nSEDGEWICK\n\n";
  test(second, size, sortSedgewickGaps);
  std::cout << '\n';
}

void testRandom()
{
  const size_t SIZE0 = 20000;
  size_t array0[SIZE0];
  initializeRandom(array0, SIZE0);
  printResults(array0, SIZE0);

  const size_t SIZE1 = 10000;
  size_t array1[SIZE1];
  initializeRandom(array1, SIZE1);
  printResults(array1, SIZE1);

  const size_t SIZE2 = 5000;
  size_t array2[SIZE2];
  initializeRandom(array2, SIZE2);
  printResults(array2, SIZE2);

  const size_t SIZE3 = 1000;
  size_t array3[SIZE3];
  initializeRandom(array3, SIZE3);
  printResults(array3, SIZE3);

  const size_t SIZE4 = 500;
  size_t array4[SIZE4];
  initializeRandom(array4, SIZE4);
  printResults(array4, SIZE4);

  const size_t SIZE5 = 100;
  int array5[SIZE5];
  initializeRandom(array5, SIZE5, 3);
  printResults(array5, SIZE5);

}
