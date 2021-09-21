#include <iostream>
#include <windows.h>
#include <cmath>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double a, b, c, D, x1, x2;
    std::cout << "Введите значение коэффицентов квадратного уравнения "<< std::endl;
    std::cin >> a >> b >> c;

    if (std::cin.peek() != '\n')
    {
        std::cout << "Коэффициенты уравнения должны быть заданы числами. Завершение программы";
    }
    else
    {
        if (a == 0)
        {
            std::cout << "Это не квадратное уравнение. Завершение программы";
        }
        else
        {
            D = pow(b,2) - (4*a*c); //дискриминант
            x1 = (-b + sqrt(D)) / (2 * a); //первый корень
            x2 = (-b - sqrt(D)) / (2 * a); //второй корень
            if (D < 0)
            {
                std::cout << "Дискриминат меньше нуля. Корней нет." << std::endl;
            }
            else
            {
                if (pow(sqrt(D), 2) != D) //целый дискриминант или нет
                {
                    std::cout << "Дискриминант не целое число. Завершение программы";
                    exit(0);
                }
                else
                {
                    std::cout << "Первый корень уравнения: " << x1 << std::endl;
                    std::cout << "Второй корень уравнения: " << x2 << std::endl;
                }

            }

        }
    }
    return 0;
}
