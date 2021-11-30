#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "counter.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size(0);
    std::string line;
    std::ifstream file("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind3\\input");
    if (file.is_open()) {
        file >> size;
    }
    int *array = new int[size];
    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file >> array[i];
            cout << array[i] << " ";
        }
    }
    cout << "\n" << "Ответ: " << counter(size, array);
    file.close();
    delete[] array;
}
