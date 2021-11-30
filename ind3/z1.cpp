#include <iostream>
#include <windows.h>
#include "counter.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int size(5);
    int array[size] = {1, 5, 3, 4, 5};
    cout << "Ответ: " << counter(size, array);
}
