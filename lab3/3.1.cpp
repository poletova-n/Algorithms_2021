#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

const char* error_invalid_first_coefficient = "Это не квадратное уравнение. Завершение программы";
const char* error_coefficient_not_number = "Коэффициенты уравнения должны быть заданы числами. Завершение программы";
const char* error_dk_error = "Корень из дискриминанта не целое число. Завершение программы";

int main()
{
    try
    {
        {
            SetConsoleOutputCP(CP_UTF8);
            double a, b, c, D, x1, x2;
            cout << "Введите значение коэффицентов квадратного уравнения "<< endl;
            cin >> a >> b >> c;

            if (cin.peek() != '\n')
            {
                throw error_coefficient_not_number;
                exit(0);
            }
            else
            {
                if (a == 0)
                {
                    throw error_invalid_first_coefficient;
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
                            throw error_dk_error;
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
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}
