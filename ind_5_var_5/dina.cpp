#include <fstream>
#include <iostream>
void printMatrix(int **arr, const int row, const int column) {
  for (int i = 0; i < column; i++) {
    for (int j = 0; j < row; j++)
      std::cout << arr[i][j] << ' ';
    std::cout << std::endl;
  }
}
int main() {
  int const n = 5;
  int const m = 5;
  int **matrix = nullptr;
  std::ifstream inp;
  try {
    // init matrix
    matrix = (int **)malloc(n * sizeof(int *) + n * m * sizeof(int));
    int *start = (int *)((char *)matrix + n * sizeof(int *));
    for (int i = 0; i < n; i++)
      matrix[i] = start + i * m;
    // int **matrix = new int *[LEN_COLUMN];
    // for (int i = 0; i < LEN_COLUMN; i++)
    // matrix[i] = new int[LEN_ROW];

    // input matrix
    inp.open("inp.txt");
    if (inp.fail())
      throw "File error";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = -1;
      }
    }
  } catch (const char *err) {
    std::cerr << "Error " << err << std::endl;
    return -1;
  }
  // 0 - down
  // 1 - right
  // 2 - up
  // 3 - left
  int i = 0, j, k = 0;
  while (i < n * m) {
    k++;
    for (j = k - 1; j < m - k + 1; j++) {
      inp >> matrix[k - 1][j];
      i++;
    }

    for (j = k; j < n - k + 1; j++) {
      inp >> matrix[j][m - k];
      i++;
    }

    for (j = m - k - 1; j >= k - 1; j--) {
      inp >> matrix[n - k][j];
      i++;
    }

    for (j = n - k - 1; j >= k; j--) {
      inp >> matrix[j][k - 1];
      i++;
    }
  }

  // check matrix
  printMatrix(matrix, n, m);

  free(matrix);
  return 0;
}
