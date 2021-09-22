#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a(0), b(0), c(0), myMax(0), myMed(0), myMin(0);
    cout << "Введите 3 стороны треугольника: \n";
    cin >> a >> b >> c;
    if (cin.fail() || cin.peek() != 10) {
        cout << "Ошибка! Введите целые числа.";
    }
    else {
        myMax = max(max(a, b), c);
        myMin = min(min(a, b), c);
        myMed = a + b + c - myMax - myMin;
        if (myMin <= 0) {
            cout << "Такого треугольника не существует. Треугольник должен содержать только положительные стороны.";
        }
        else if (myMax > myMed + myMin) {
            cout << "Такого треугольника не существует. Наибольшая сторона больше суммы двух других.";
        }
        else {
            if (myMax == myMin == myMed) {
                cout << "Треугольник равносторонний. \n";
            }
            else if (a == b or a == c or b == c) {
                cout << "Треугольник равнобедренный. \n";
            }
            else {
                cout << "Треугольник разносторонний. \n";
            }
            if (myMax * myMax == myMed * myMed + myMin * myMin) {
                cout << "Треугольник прямоугольный.";
            }
            else if (myMax * myMax < myMed * myMed + myMin * myMin) {
                cout << "Треугольник остроугольный.";
            }
            else {
                cout << "Треугольник тупоугольный.";
            }
        }
    }
}
