#include <iostream>
#include "test-sorts.hpp"
#include "shell-sort.hpp"

template <typename T>
void printArray(T* list, const size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << list[i] << " ";
  }
  std::cout << "\n";
}

void testRand()
{
  std::cout << "\n--------TEST RANDOM--------\n";
  testRandom();
}
void testBestWorst()
{
  const size_t size = 30000;
  long array1[size];
  long array2[size];
  long array3[size];
  for (int i = 0; i < size; i++)
  {
    array1[i] = i;
    array2[i] = i;
    array3[i] = i;
  }
  long array4[size];
  long array5[size];
  long array6[size];
  for (int i = size - 1, j = 0; i >= 0; i--, j++)
  {
    array4[j] = i;
    array5[j] = i;
    array6[j] = i;
  }

  std::cout << "\nWORST CASE:\n\n";
  std::cout << "\nSHELL GAPS, N/(2^k)\n\n";
  test(array1, size, sortShellGaps);
  std::cout << "\nHIBBARD GAPS, (2^k - 1)\n\n";
  test(array2, size, sortHibbardGaps);
  std::cout << "\nSEDGEWICK GAPS\n\n";
  test(array3, size, sortSedgewickGaps);
  std::cout << "\nBEST CASE:\n\n";
  std::cout << "\nSHELL GAPS, N/(2^k)\n\n";
  test(array4, size, sortShellGaps);
  std::cout << "\nHIBBARD GAPS, (2^k - 1)\n\n";
  test(array5, size, sortHibbardGaps);
  std::cout << "\nSEDGEWICK GAPS\n\n";
  test(array6, size, sortSedgewickGaps);
}
int main()
{
  std::cout << "Test Work\n";
  int arr1[7]{ 3,4,1,5,6,2,2 };
  sortShellGaps(arr1, 7);
  printArray(arr1, 7);
  int arr2[6]{ 3,5,1,0,4,0 };
  sortHibbardGaps(arr2,6);
  printArray(arr2, 6);
  int arr3[9]{ 3,4,8,9,0,100,110,2,2 };
  sortSedgewickGaps(arr3, 9);
  printArray(arr3, 9);



  //testBestWorst();
  testRand();
}

