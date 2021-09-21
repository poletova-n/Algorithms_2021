#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double a, b, c, D, x1, x2;
    cout << "Введите значение коэффицентов квадратного уравнения "<< endl;
    cin >> a >> b >> c;

    if (cin.peek() != '\n')
    {
        cout << "Коэффициенты уравнения должны быть заданы числами. Завершение программы";
        exit(0);
    }
    else
    {
        if (a == 0)
        {
            cout << "Это не квадратное уравнение. Завершение программы";
            exit(0);
        }
        else
        {
            D = pow(b,2) - (4*a*c); //дискриминант
            x1 = (-b + sqrt(D)) / (2 * a); //первый корень
            x2 = (-b - sqrt(D)) / (2 * a); //второй корень
            if (D < 0)
            {
                cout << "Дискриминат меньше нуля. Корней нет." << endl;
                exit(0);
            }
            else
            {
                if (pow(sqrt(D), 2) != D) //иррациональность дискриминанта
                {
                    cout << "Корень из дискриминанта не целое число. Завершение программы";
                    exit(0);
                }
                else
                {
                    cout << "Первый корень уравнения: " << x1 << endl;
                    cout << "Второй корень уравнения: " << x2 << endl;
                }
            }
        }
    }
    return 0;
}
