#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

const string ERROR_INVALID_COF = "Ошибка! Коэффициенты должны быть заданы целыми числами, завершение программы.";

const string ERROR_INVALID_FIRST_COF = "Ошибка! Коэффициент x^2 не может быть равен нулю, завершение программы.";

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        int a, b, c;
        double x1(0.0), x2(0.0), d(0.0);
        cout << "Введите 3 коэффициента: \n";
        cin >> a >> b >> c;
        if (cin.fail() || cin.peek() != 10) {
            throw ERROR_INVALID_COF;
        }
        else {
            if (a == 0) {
                throw ERROR_INVALID_FIRST_COF;
            } else {
                d = pow(b, 2) - 4 * a * c;
                if (d < 0) {
                    cout << "Дискриминант отрицательный. Корней нет!";
                } else if (d == 0) {
                    cout << "Корень уравнения:" << "\n" << (-b + sqrt(d)) / 2 / a;
                } else if (sqrt(d) - int(sqrt(d)) > 0) {
                    cout << "Корень из дискриминанта не целое число.";
                } else {
                    x1 = (-b + sqrt(d)) / 2 / a;
                    x2 = (-b - sqrt(d)) / 2 / a;
                    cout << "Корни уравнения:" << "\n" << x1 << " " << x2;
                }
            }
        }
    }
    catch(const string& error) {
        cerr << endl << error << endl;
        return -1;
    }
}