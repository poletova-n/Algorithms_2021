#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a(0), b(0), c(0);
    cout << "Введите 3 числа: \n";
    cin >> a >> b >> c;
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Введите целые числа.";
    }
    else {
        cout << "Наибольшее число: " << max(max(a, b), c);
    }
}
