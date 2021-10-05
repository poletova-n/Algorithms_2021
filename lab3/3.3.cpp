#include <iostream>
#include <windows.h>
using namespace std;
const char* error_value_not_number = "Длины сторон треугольника должны быть заданы числами. Завершение программы.";
const char* error_value_less_zero = "Значения длин сторон треугольника должны быть больше нуля. Завершение программы.";
const char* error_triangle_doesnt_exist = "Такого треугольника не существует.Завершение программы.";
int main()
{
    try {
        SetConsoleOutputCP(CP_UTF8);
        int a, b, c;
        cout << "Введите длины строн треугольника в порядке неубывания" << endl;
        cin >> a >> b >> c;

        if (cin.peek() != '\n')
        {
            throw error_value_not_number;
        }
        else if (a <= 0 || b <= 0 || c <= 0)
        {
            throw error_value_less_zero;
        }
        else
        {
            if (a+b < c || a+c < b || b+c < a)    //проверка на существование треугольника
            {
                throw error_triangle_doesnt_exist;
            }
            else
            {
                if (a == b and b != c)
                {
                    cout<< "Треугольник равнобедренный";
                }
                else
                {
                    if (a == b and b == c)
                    {
                        cout << "Треугольник равносторонний";
                    }
                    else {
                        if (pow(a, 2) + pow(b, 2) > pow(c, 2)) {
                            cout << "Треугольник остроугольный";
                        }
                        if (pow(a, 2) + pow(b, 2) < pow(c, 2)) {
                            cout << "Треугольник тупоугольный";
                        }
                        if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                            cout << "Треугольник прямоугольный";
                        }
                    }
                }
            }
        }
        return 0;
        }
    catch (const char* error)
    {
       cerr << endl << error << endl;
    }
}
