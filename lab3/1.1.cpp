#include <cmath>
#include <iostream>
#include <windows.h>

const char* error_invalid_first_coefficient = "Это не квадратное уравнение. Завершение программы";
const char* error_coefficient_not_number = "Коэффициенты уравнения должны быть заданы числами. Завершение программы";
const char* error_disk_zero = "Дискриминат меньше нуля. Корней нет.";
const char* error_disk_not_whole = "Дискриминант не целое число. Завершение программы";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    float x1, x2, D, a, b, c;
    try
    {
        std::cout << "Введите значение коэффицентов квадратного уравнения "<< std::endl;
        std::cin >> a >> b >> c;
        if (std::cin.peek() != '\n')
        {
            throw error_coefficient_not_number;
        }
        if (a == 0)
        {
            throw error_invalid_first_coefficient ;
        }
        else
        {
            D = pow(b, 2) - (4 * a * c);
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            if (D < 0)
            {
                throw error_disk_zero;
            } else
            {
                if (pow(sqrt(D), 2) != D)
                {
                    throw error_disk_not_whole ;
                }
                else
                {
                    std::cout << "Первый корень уравнения: " << x1 << std::endl;
                    std::cout << "Второй корень уравнения: " << x2 << std::endl;
                }
            }
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}


