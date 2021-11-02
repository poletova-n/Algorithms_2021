#include <iostream>
#include <windows.h>
using namespace std;

const char* ERROR_NOT_NUMBER = "Вы ввели не натуральное число!";

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        int n(0);
        cout << "Введите сторону квадрата: " << "\n";
        cin >> n;
        if (cin.fail() or cin.peek() != 10 or n <= 0) {
            throw ERROR_NOT_NUMBER;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "* ";
            }
            cout << "\n";
        }
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}
