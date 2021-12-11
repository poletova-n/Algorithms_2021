#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int x1(0), y1(0);
    int x2(0), y2(0);
    cout << "Координаты: \n";
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if ((cin.fail() or cin.peek() != 10) or x1 < 1 or y1 < 1 or x2 < 0 or y2 < 0 or \
    x1 > 8 or y1 > 8 or x2 > 8 or y2 > 8) {
        cout << "Ошибка! Координаты должны быть натуральными числами до 8.";
    }
    else {
        if ((abs(x1 - x2) == abs(y1 - y2)) or ((x1 - x2 == 0) or (y1 - y2 == 0))) {
            cout << "Истина.";
        }
        else {
            cout << "Ложь.";
        }
    }
}
