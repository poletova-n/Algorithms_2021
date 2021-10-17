#include <iostream>
#include <windows.h>
using namespace std;

const string ERROR_NOT_NUMBER = "Ошибка! Введите целое число.";

const string ERROR_NOT_POSITIVE_NUMBER = "Ошибка! Введите неотрицательное число.";

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        int n(0);
        cout << "Введите число ворон: \n";
        cin >> n;
        if (cin.fail() || cin.peek() != 10) {
            throw ERROR_NOT_NUMBER;
        } else if (n < 0) {
            throw ERROR_NOT_POSITIVE_NUMBER;
        } else {
            if (n % 10 == 1 and n % 100 != 11) {
                cout << "В стае " << n << " ворона";
            } else if ((n % 10 >= 5 and n % 10 <= 9) or (n % 100 >= 11 and n % 100 <= 19) or (n % 10 == 0)) {
                cout << "В стае " << n << " ворон";
            } else {
                cout << "В стае " << n << " вороны";
            }
        }
    }
    catch (const string& error) {
        cerr << endl << error << endl;
        return -1;
    }
}
