#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

const char* INVALID_RANGE = "Неверно заданы пределы диапазона!";
const char* INVALID_MAX_NUMBER = "Неверно задано максимальное число последовательности!";
const char* INVALID_ABS_ERROR = "Неверно задана абсолютная погрешность!";

double result(double x, int numberMax, double absError);
double up(double n);
double down(double n);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x1(0), x2(0);
    int numberMax(0);
    double shag(0);
    double absError(0);
    try {
        cout << "Введите интервал от x1 и x2: ";
        cin >> x1 >> x2;
        if(((x1 >= 1.0 or x1 <= -1.0) or (x2 >= 1.0 or x2 <= -1.0)) or (cin.peek() != 10 and cin.peek() != 32)) {
            throw INVALID_RANGE;
        }
        cout << "\n" <<"Введите шаг интервала: ";
        cin >> shag;
        if(shag < 0 or (shag > abs(x2) or shag > abs(x1)) or (cin.peek() != 10 and cin.peek() != 32)) {
            throw INVALID_RANGE;
        }
        cout << "\n" << "Введите число последовательности: ";
        cin >> numberMax;
        if((cin.peek() != 10 and cin.peek() != 32) or numberMax < 1) {
            throw INVALID_MAX_NUMBER;
        }
        cout << "\n" << "Введите абсолютную погрешность: ";
        cin >> absError;
        if (cin.fail() or cin.peek() != 10) {
            throw INVALID_ABS_ERROR;
        }
        cout << "\n "<< "--------------------------------\n";
        cout << "X\tЗначение\n";
        cout << "--------------------------------\n";
        for (double i = x1; i <= x2; i += abs(shag)) {
            double ans = result(i, numberMax, absError);
            if(ans < 0 and ans > -1.38778e-16) {
                cout << "0   " << "     " << ans << "\n";
            }
            else {
                if(ans == 1) {
                    cout << "Точность не достигнута!" << "\n";
                }
                else {
                    cout << i << "     " << ans << "\n";
                }
            }
        }
        cout << "--------------------------------";
    }
    catch (const char* error) {
        cerr << "\n" << error << "\n";
        return -1;
    }
}

double result(double x, int numberMax, double absError) {
    int i = 1;
    double term;
    double sum(1.0);
    do {
        term = (up(i) / down(i)) * pow(x, (i * 2));
        term = round(term*(1/absError))/(1/absError);
        i++;
        sum += term;
    }
    while(i <= numberMax and absError <= abs(term));
    if (absError <= abs(term)) {
        return 1;
    }
    return sum;
}

double up(double n) {
    double num = 1.0;
    for (int i = 1; i <= n; ++i) {
        num *= (i + i - 1.0);
    }
    return num;
}

double down(double n) {
    double den = 1.0;
    for (int i = 1; i <= n; ++i) {
        den *= (i + i);
    }
    return den;
}
