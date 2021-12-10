
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <exception>

namespace laba3 {

    int func(const int* arr, const int N);

}



int laba3::func(const int* arr, const int N) {

    int k = 0;

    for (int i = 0; i < N - 2; i++) {

        if (arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2]) k++;

    }

    return k;

}


int main() {

    const int arr1[10] = { 1, 2, 3, 7, 5, 6, 4, 3, 9, 2 };

    for (int i = 0; i < 10; i++) std::cout << arr1[i] << " ";

    std::cout << std::endl;

    std::cout << "Number of triplets: " << laba3::func(arr1, 10) << std::endl;

    try {

        int n = 0;

        std::cout << "enter the number of elements: "; std::cin >> n;

        if (std::cin.fail()) throw std::logic_error("Error");

        else {

            int* arr2 = new int[n];

            for (int i = 0; i < n; i++) arr2[i] = rand();

            for (int i = 0; i < n; i++) std::cout << arr2[i] << " ";

            std::cout << std::endl;

            std::cout << "Number of triplets: " << laba3::func(arr2, n) << std::endl;

        }

        std::ifstream file("../file.txt");

        if (file.is_open()) {

            int N = 0;

            while (file >> N) {

                int* arr = new int[N];

                for (int i = 0; i < N; i++)
                    file >> arr[i];

                for (int i = 0; i < N; i++)
                    std::cout << arr[i] << " ";

                std::cout << std::endl;

                std::cout << "Number of triplets: " << laba3::func(arr, N) << std::endl;

                delete[] arr;

            }

            file.close();

        }

        else throw std::logic_error("could not open input file");

    }

    catch (const std::logic_error& error) {

        std::cerr << error.what();

    }

    return 0;

}