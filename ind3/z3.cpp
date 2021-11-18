#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int count(int size, int* x);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n;
    std::string line;
    std::ifstream file("C:\\Users\\miha1\\CLionProjects\\Algorithms_2021\\ind3\\input");
    if (file.is_open()) {
        file >> n;
    }
    int *array = new int[n];
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file >> array[i];
            cout << array[i] << " ";
        }
    }

    cout << "\n" << "Ответ: " << count(n,array);
    file.close();
    delete[] array;
}

int count(int size, int* array) {
    int myMax = INT_MIN;
    int count(1);
    for (int i = 0; i < size; ++i) {
        if (myMax == array[i]) {
            count += 1;
        }
        myMax = max(array[i], myMax);
    }
    delete [] array;
    return count;
}