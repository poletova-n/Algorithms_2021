#include <iostream>
#include <windows.h>
using namespace std;

const char* ERROR_NOT_NUMBER = "Вы ввели не число!";
const char* ERROR_LIMIT_BOARD = "Координаты должны принимать значения от 1 до 8!";

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        int x(0), y(0);
        cout << "Введите координаты: ";
        cin >> x >> y;
        if (cin.fail() or cin.peek() != 10) {
            throw ERROR_NOT_NUMBER;
        }
        if (x < 1 or y < 1 or x > 8 or y > 8) {
            throw ERROR_LIMIT_BOARD;
        }
        cout << "Позиции под атакой: " << "\n";
        for (int i = 1; i <= 8; ++i) {
            if(i != x) {
                cout << "(" << i << ", " << y << ")" << " ";
            }
        }
        cout << "\n";
        for (int i = 1; i <= 8; ++i) {
            if(i != y) {
                cout << "(" << x << ", " << i << ")" << " ";
            }
        }
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}
