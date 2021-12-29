#include "function2.h"

#include <fstream>

void input(int* arr, int X, int Y, std::ifstream& file) {

    for (int y = 0; y < Y; y++) {

        for (int x = 0; x < X; x++) {

            file >> arr[y * X + x];

        }

    }

}

int search(const int* arr, int X, int Y) {

    int maxLen = 0, num = 0, maxNum = 0;

    for (int x = 0; x < X; x++) {

        int len = 0;

        num++;

        for (int i = 0; i < Y; i++) {

            for (int j = i + 1; j < Y; j++) {

                if (arr[i * X + x] == arr[j * X + x]) {

                    len++;

                }

            }

        }

        if (len > maxLen) {

            maxLen = len;

            maxNum = num;

        }

    }

    return maxNum;

}

void output(const int* arr, int X, int Y) {

    std::ofstream file2("../file5.txt");

    if (file2.is_open()) {

        file2 << search(arr, X, Y);

        file2.close();

    }

    else {

        throw std::ios_base::failure::exception("can not open file5.txt");

    }

}

void laba5::second() {

    int X = 0, Y = 0;

    std::ifstream file("../file5_2.txt");

    if (file.is_open()) {

        file >> X;

        if (file.fail()) {

            throw std::logic_error("incorrect matrix");

        }

        else {

            Y = X;

            int* arr = new int[X * Y];

            input(arr, X, Y, file);

            output(arr, X, Y);

        }

        file.close();

    }

    else {

        throw std::ios_base::failure::exception("can not open file5_2.txt");

    }

}