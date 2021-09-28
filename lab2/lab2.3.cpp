#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a[3] = {0, 0, 0}, n(0), count(0);
    cout << "Введите 3 числа: \n";
    for (int i = 0; i <= 2; ++i) {
        cin >> a[i];
    }
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Введите 3 целых числа.";
    }
    else {
        n = a[0];
        for (int i = 0; i <= 2; ++i) {
            if (n == a[i]) {
                count += 1;
            }
        }
        if (a[1] == a[2] and a[0] != a[1]) {
            count += 1;
        }
        cout << "Количество совпадающих чисел: " << count;
    }

}
