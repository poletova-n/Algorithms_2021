#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a, b, c;
    double x1(0.0), x2(0.0), d(0.0);
    cout << "Введите 3 коэффициента: \n";
    cin >> a >> b >> c;
    if (cin.fail() || cin.peek() != 10) {
        cout << "Ошибка! Введенные коэффициенты некоректны.";
    }
    else {
        if (a == 0) {
            cout << "Ошибка! Задано не квадратное уравнение.";
        }
        else {
            d = pow(b, 2) - 4 * a * c;
            if (d < 0) {
                cout << "Дискриминант отрицательный. Корней нет!";
            }
            else if (d == 0) {
                cout << "Корень уравнения:" << "\n" << (-b + sqrt(d)) / 2 / a;
            }
            else if (sqrt(d) - int(sqrt(d)) > 0) {
                cout << "Корень из дискриминанта не целое число.";
            }
            else {
                x1 = (-b + sqrt(d)) / 2 / a;
                x2 = (-b - sqrt(d)) / 2 / a;
                cout << "Корни уравнения:" << "\n" << x1 << " " << x2;
            }
        }
    }
}
