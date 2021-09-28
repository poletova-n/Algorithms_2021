#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a[3] = {0, 0, 0};
    bool flag1(false), flag2(false);
    cout << "Введите 3 числа: \n";
    for (int i = 0; i <= 2; ++i) {
        cin >> a[i];
    }
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Введите 3 целых числа.";
    }
    else {
        for (int i = 0; i <= 2; ++i) {
            if (a[i] % 2 == 0) {
                flag1 = true;
            }
            else {
                flag2 = true;
            }
        }
        if (flag1 and flag2) {
            cout << "ДА";
        }
        else {
            cout << "НЕТ";
        }
    }
}
