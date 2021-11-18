#include <iostream>
#include <windows.h>
using namespace std;

const char* ERROR_INCORRECT_INPUT = "Размер массива должен быть больше 0.";

int main() {
    int n(0);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите размер массива:";
    cin >> n;
    if(cin.fail() or cin.peek() != 10 or n < 1)
    {
        cerr << ERROR_INCORRECT_INPUT;
        return -1;
    }
    int* array = new int[n];
    int count(1), x(0);
    int myMax = INT_MIN;
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 10 + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << array[i] << ' ';
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        if (myMax == array[i]) {
            count += 1;
        }
        myMax = max(array[i], myMax);
    }
    cout << "Ответ: " << count;
    delete [] array;
}
