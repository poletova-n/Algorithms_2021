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
        int addX = 1, addY = 1, z = 0;
        cout << "Позиции под атакой: " << "\n";
        for (int i = 0; i < 4; ++i) {
            while (x + addX <= 8 and y + addY <= 8 and x + addX >= 1 and y + addY >= 1) {
                cout << "(" << x + addX << ", " << y + addY << ") ";
                z++;
                if(addX > 0) {
                    addX++;
                }
                else {
                    addX--;
                }
                if(addY > 0) {
                    addY++;
                }
                else {
                    addY--;
                }
            }
            if (!(x == 1 or x == 8 or y == 1 or y == 8)) {
                cout << "\n";
            }
            if(i == 0) {
                addX = -1;
                addY = 1;
            }
            if(i == 1) {
                addX = -1;
                addY = -1;
            }
            if(i == 2) {
                addX = 1;
                addY = -1;
            }
        }
    }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}
