#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n(0);
    cout << "Введите год: \n";
    cin >> n;
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Год должен содержать число.";
    }
    else {
        if ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0) {
            cout << "Год високосный.";
        }
        else {
            cout << "Год невисокосный.";
        }
    }
}
