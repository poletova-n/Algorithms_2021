#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a[3] = {0, 0, 0};
    cout << "Введите 3 числа: \n";
    for (int i = 0; i <= 2; ++i) {
        cin >> a[i];
    }
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Введите 3 целых числа.";
    }
    else {
        sort(a, a + 3);
        for (int i = 0; i <= 2; ++i) {
            cout << a[i] << " ";
        }
    }
}
