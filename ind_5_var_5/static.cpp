#include <fstream>
#include <iostream>
using namespace std;
int **snailInput(int **arr, int *inp, const int n, const int m) {
  // 0 - down
  // 1 - right
  // 2 - up
  // 3 - left
  int i = 0, j, k = 0;
  int index = 0;
  while (i < n * m) {
    k++;
    for (j = k - 1; j < m - k + 1; j++) {
      arr[k - 1][j] = inp[index++];
      i++;
    }

    for (j = k; j < n - k + 1; j++) {
      arr[j][m - k] = inp[index++];
      i++;
    }

    for (j = m - k - 1; j >= k - 1; j--) {
      arr[n - k][j] = inp[index++];
      i++;
    }

    for (j = n - k - 1; j >= k; j--) {
      arr[j][k - 1] = inp[index++];
      i++;
    }
  }
  return arr;
}
int countCheckZeroColumn(int **arr, const int column, const int row) {
  int count = 0;
  for (int i = 0; i < column; i++) {
    for (int j = 0; j < row; j++) {
      if (arr[j][i] == 0) {
        count += 1;
        break;
      }
    }
  }
  return count;
}
void printMatrix(int **arr, const int column, const int row) {
  for (int i = 0; i < column; i++) {
    for (int j = 0; j < row; j++)
      cout << arr[i][j] << ' ';
    cout << endl;
  }
}
int main() {
  // init matrix
  const int LEN_ROW = 5;
  const int LEN_COLUMN = 5;
  int **matrix = nullptr;
  int *inpArr = nullptr;
  ifstream inp;
  ofstream out;
  try {
    matrix = (int **)malloc(LEN_COLUMN * sizeof(int *) +
                            LEN_COLUMN * LEN_ROW * sizeof(int));
    int *start = (int *)((char *)matrix + LEN_COLUMN * sizeof(int *));
    for (int i = 0; i < LEN_COLUMN; i++)
      matrix[i] = start + i * LEN_ROW;

    inpArr = new int[LEN_ROW * LEN_COLUMN];

    // input matrix
    inp.open("inp.txt");
    out.open("out.txt");
    if (inp.fail() || out.fail())
      throw "File error";

  } catch (const char *err) {
    cerr << err << endl;
    return -1;
  }
  for (int i = 0; i < LEN_ROW * LEN_COLUMN; i++)
    inp >> inpArr[i];

  for (int i = 0; i < LEN_ROW; i++)
    for (int j = 0; j < LEN_COLUMN; j++)
      matrix[i][j] = inpArr[i * LEN_ROW + j];

  // check matrix
  printMatrix(matrix, LEN_COLUMN, LEN_ROW);

  cout << countCheckZeroColumn(matrix, LEN_COLUMN, LEN_ROW) << endl;
  out << countCheckZeroColumn(matrix, LEN_COLUMN, LEN_ROW);

  snailInput(matrix, inpArr, LEN_COLUMN, LEN_ROW);
  printMatrix(matrix, LEN_COLUMN, LEN_ROW);

  free(matrix);
  return 0;
}
