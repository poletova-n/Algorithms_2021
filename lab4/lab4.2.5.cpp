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
        int space = n - 1;
        for (int i = 0; i < n; ++i) {
            cout << "\n";
            for (int j = 0; j < space + 1; ++j) {
                cout << " ";
            }
            for (int j = 0; j <= i - 1; ++j) {
                cout << "* ";
            }
            space--;
        }
        space = 0;
        for (int i = n; i > -1; --i) {
            cout << std::endl;
            for (int j = 0; j < space; j++) {
                cout << " ";
            }
            for (int j = 0; j < i; ++j) {
                cout << "* ";
            }
            space++;
        }
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}
