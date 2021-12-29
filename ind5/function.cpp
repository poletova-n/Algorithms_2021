#include "function.h"

#include <iostream>

#include <fstream>

#include <iomanip>

void laba5::printArr(const int* arr, int X, int Y) {

    std::cout << "Arr[" << X << "][" << Y << "]: {" << std::endl;

    for (int y = 0; y < Y; y++) {

        std::cout << std::setw(4);

        for (int x = 0; x < X; x++) {

            std::cout << std::setw(4) << arr[y * X + x];

        }

        std::cout << std::endl;

    }

    std::cout << "};" << std::endl;

}

int search(const int* arr, int X, int Y) {

    int count = 0;

    for (int x = 0; x < X; x++) {

        bool is_finded = false;

        for (int i = 0; i < Y && !is_finded; i++) {

            for (int j = i + 1; j < Y && !is_finded; j++) {

                if (arr[i * X + x] == arr[j * X + x]) {

                    is_finded = true;

                    count++;

                }

            }

        }

    }

    return count;

}

void output(const int* arr) {

    std::ofstream file("../file5_1.txt");

    if (file.is_open()) {

        file << search(arr, 5, 5);

    }

    else {

        throw std::ios_base::failure::exception("can not open file5_1.txt");

    }

}

void laba5::first() {

    int arr[5 * 5] = {

            1, 2, 3, 4, 5,

            6, 7, 8, 9, 0,

            9, 8, 7, 6, 5,

            4, 3, 2, 1, 0,

            5, 5, 5, 5, 5

    };

    laba5::printArr(arr, 5, 5);

    std::cout << "number of columns: " << search(arr, 5, 5) << std::endl;

    output(arr);

}