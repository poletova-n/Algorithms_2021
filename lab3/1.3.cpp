#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа!";
const string ERROR_NOT_POSITIVE_NUMBER = "Вводить можно только положительные числа!";
const string ERROR_NOT_TRIANGLE = "Такого треугольника не существует!";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        double a, b, c; //Вводим переменные

        cout << "Введите стороны треугольника: ";

        cin >> a >> b >> c; //Вводим значения

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a < 0 || b < 0 || c < 0) //Проверям, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else if (a > b + c || b > a + c || c > a + b)
        {
            throw ERROR_NOT_TRIANGLE;
        }
        else
        {
            cout << "a: " << a << endl << " b: " << b << endl << " c: " << c;
            if (a == b && a == c && b == c) //Если все стороны равны, то треугольник равностороний
            {
                cout << endl << "Треугольник: равностороний";
            }
            else if (a == b && a == c && b == c) //Если две боковые стороны равны, то треугольник равнобедренный
            {
                cout << endl << "Треугольник: равнобедренный";
            }
            else if (pow(c, 2) == pow(a, 2) + pow(b, 2)) //Если квадрат стороны С равен сумме квадратов сторон А и В, то треугольник равностороний
            {
                cout << endl << "Треугольник: прямоугольный";
            }
            else if (pow(c, 2) < pow(a, 2) + pow(b, 2)) //Если квадрат стороны С меньше сумме квадратов сторон А и В, то треугольник равностороний
            {
                cout << endl << "Треугольник: остроугольный";
            }
            else
            {
                cout << endl << "Треугольник: тупоугольный";
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}
