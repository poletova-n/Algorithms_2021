#include <iostream>
#include <windows.h>
#include "counter.h"
using namespace std;

const char* ERROR_INCORRECT_INPUT = "Размер массива должен быть больше 0.";

int main() {
    int size(0);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите размер массива:";
    cin >> size;
    if(cin.fail() or cin.peek() != 10 or size < 1)
    {
        cerr << ERROR_INCORRECT_INPUT;
        return -1;
    }
    int* array = new int[size];
    int count(1), x(0);
    int myMax = INT_MIN;
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << "\n" << "Ответ: " << counter(size, array);
    delete [] array;
}
