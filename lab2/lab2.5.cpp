#include <iostream>
#include <windows.h>
using namespace std;

int coord(int x, int y);
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x1(0), y1(0), x2(0), y2(0);
    cout << "Введите координаты двух точек: \n";
    cin >> x1 >> y1 >> x2 >> y2;
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Координаты задаются целыми числами.";
    }
    if (coord(x1, y1) == coord(x2, y2)) {
        cout << "ДА";
    }
    else {
        cout << "НЕТ";
    }
}

int coord(int x, int y) {
    if (x > 0 and y > 0) {
        return 1;
    }
    else if (x < 0 and y > 0) {
        return 2;
    }
    else if (x < 0 and y < 0) {
        return 3;
    }
    else {
        return 4;
    }
}