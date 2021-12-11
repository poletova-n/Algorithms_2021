#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n(0);
    cout << "Введите число ворон: \n";
    cin >> n;
    if (cin.fail() || cin.peek() != 10) {
        cout << "Ошибка! Введите целое число.";
    }
    else if (n < 0) {
        cout << "Ошибка! Введите неотрицательное число.";
    }
    else {
        if (n % 10 == 1 and n % 100 != 11) {
            cout << "В стае " << n << " ворона";
        } else if ((n % 10 >= 5 and n % 10 <= 9) or (n % 100 >= 11 and n % 100 <= 19) or (n % 10 == 0)) {
            cout << "В стае " << n << " ворон";
        } else {
            cout << "В стае " << n << " вороны";
        }
    }
}
