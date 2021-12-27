#include <iostream>
void printArr(int **arr, const int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
int uniqLine(int **arr, const int len) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int *line = arr[i];
    bool isUniq = true;
    for (int j = 0; j < len; j++) {
      for (int z = 0; z < len; z++) {
        if (line[j] == line[z] && j != z) {
          isUniq = false;
          break;
        }
      }
      if (!isUniq)
        break;
    }
    delete[] line;
    if (isUniq)
      count += 1;
  }
  return count;
}
int main() {
  // Create 2d matrix
  const int LEN = 10;
  int **m = new int *[LEN];
  for (int i = 0; i < LEN; i++)
    m[i] = new int[LEN];

  // Init value on matrix
  for (int i = 0; i < LEN; i++)
    for (int j = 0; j < LEN; j++)
      m[i][j] = std::abs(i - j);

  // Print matrix
  printArr(m, LEN);

  // Check 9 variant Dime
  std::cout << uniqLine(m, LEN) << std::endl;

  // Free memory
  for (int i = 0; i < LEN; i++)
    delete[] m[i];
  delete[] m;

  return 0;
}
