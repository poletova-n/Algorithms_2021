#include <iostream>
#include <iomanip>
#include <fstream>

namespace errorMessages {
    const char* sizeValue = "Expected size value more than 0\n";
    const char* rawsValue = "Expected raws value more than 0\n";
    const char* columnsValue = "Expected columns value more than 0\n";
}

const int COLUMNS = 10;

int rawsOnlyMoreThanZero(int matrix[][COLUMNS], int raws, int columns);
void printSquareMatrix(int** matrix, int size, std::ostream& fout);
void fillMatrix(int** matrix, int size);

int main() {
    // 1
    const int RAWS = 4;

    int matr[RAWS][COLUMNS] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {0, 1, 2, 3, 3, 3, 3, 3, 3, 3},
        {-1, -2, 34, 3, 3, 3, 3, 3, 3, 10},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    
    std::cout << "Built-in:\n";
    std::cout << rawsOnlyMoreThanZero(matr, RAWS, COLUMNS) << std::endl << std::endl;

    // 2
    int N = 1;
    std::cout << "Dynamic:\n";
    
    try {
        std::ifstream fin("C:/Users/KRATOS/Desktop/Программирование/06.11.2021/Инд_задание_5_Матрицы/FileIn.txt");
        fin >> N;
        fin.close();

        if (N <= 0) {
            throw errorMessages::sizeValue;
        }

        int** matrix = new int* [N];
        for (int i = 0; i < N; ++i) {
            matrix[i] = new int[N];
        }

        fillMatrix(matrix, N);

        std::ofstream fout("C:/Users/KRATOS/Desktop/Программирование/06.11.2021/Инд_задание_5_Матрицы/FileOut.txt");
        printSquareMatrix(matrix, N, fout);
        fout.close();

        for (int i = 0; i < N; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    catch (const char* errorMsg) {
        std::cerr << errorMsg;
        return -1;
    }

    return 0;
}


int rawsOnlyMoreThanZero(int matrix[][COLUMNS], int raws, int columns) {
    if (raws <= 0) {
        throw errorMessages::rawsValue;
    }
    if (columns <= 0) {
        throw errorMessages::columnsValue;
    }

    int totalRowsCount = 0;
    for (int raw = 0; raw < raws; ++raw) {
        bool isMatch = true;
        for (int column = 0; column < columns && isMatch; ++column) {
            if (matrix[raw][column] <= 0) {
                isMatch = false;
            }
        }
        if (isMatch) {
            ++totalRowsCount;
        }
    }

    return totalRowsCount;
}

void printSquareMatrix(int** matrix, int size, std::ostream& fout) {
    if (size <= 0) {
        throw errorMessages::sizeValue;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            fout << std::setw(static_cast<int>(floor(log10(size * size)) + 2)) << matrix[i][j];
        }
        fout << std::endl;
    }
}

void fillMatrix(int** matrix, int size) {
    if (size <= 0) {
        throw errorMessages::sizeValue;
    }

    int count = 1;
    if (size % 2 == 1) {
        matrix[size / 2][size / 2] = size * size;
    }

    for (int layer = 0; layer < size / 2; ++layer) {
        int j = size - layer - 1;
        int i = layer;
        for (int iterNum = 0; iterNum < size - 2 * layer; ++iterNum) {
            matrix[j--][i] = count;
            ++count;
        }
        j++;
        i++;
        for (int iterNum = 0; iterNum < size - 2 * layer - 1; ++iterNum) {
            matrix[j][i++] = count;
            ++count;
        }
        i--;
        j++;
        for (int iterNum = 0; iterNum < size - 2 * layer - 1; ++iterNum) {
            matrix[j++][i] = count;
            ++count;
        }
        j--;
        i--;
        for (int iterNum = 0; iterNum < size - 2 * layer - 2; ++iterNum) {
            matrix[j][i--] = count;
            ++count;
        }
        i++;
        j--;
    }
}
