#include <iostream>
#include <windows.h>
#include <cmath>


const char* error_value_not_number = "Длины сторон треугольника должны быть заданы числами. Завершение программы.";
const char* error_value_less_zero = "Значения длин сторон треугольника должны быть больше нуля. Завершение программы.";
const char* error_triangle_not_exist = "Такого треугольника не существует.Завершение программы.";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a, b, c, ab, ac, bc;
    try
    {
        std::cout << "Введите длины строн треугольника." << std::endl;
        std::cin >> a >> b >> c;
        if (std::cin.peek() != '\n')
        {
            throw error_value_not_number;
        }
        else if (a <= 0 || b <= 0 || c <= 0)
        {
            throw error_value_less_zero;
        }
        else
        {
            ab = a + b;
            ac = a + c;
            bc = c + b;
            if (ab < c || ac < b || bc < a)
            {
                throw error_triangle_not_exist;
            }
            else
            {
                if (pow(a, 2) + pow(b, 2) > pow(c, 2))
                {
                    if (a == b and b == c)
                    {
                        std::cout << "Треугольник остроугольный и равносторонний";
                    }
                    else if ((a == b and b != c) or (a == c and a != b) or (b == c and c != a))
                    {
                        std::cout << "Треугольник остроугольный и равнобедренный";
                    }
                    else
                    {
                        std::cout << "Треугольник остроугольный";
                    }


                }
                else if (pow(a, 2) + pow(b, 2) < pow(c, 2))
                {
                    if ((a == b and a != c) or (a == c and a != b) or (b == c and c != a))
                    {
                        std::cout << "Треугольник тупоугольный и равнобедренный";
                    }
                    else
                    {
                        std::cout << "Треугольник тупоугольный";
                    }
                }
                else if (pow(a, 2) + pow(b, 2) == pow(c, 2))
                {
                    if ((a == b and a != c) or (a == c and a != b) or (b == c and c != a))
                    {
                        std::cout << "Треугольник прямоугольный и равнобедренный";
                    }
                    else
                    {
                        std::cout << "Треугольник прямоугольный";
                    }

                }
            }
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }

}
