#include <iostream>
#include <windows.h>
#include <cmath>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a, b, c, ab, ac, bc;
    std::cout << "Введите длины строн треугольника." << std::endl;
    std::cin >> a >> b >> c;
    if (std::cin.peek() != '\n')
    {
        std::cout << "Длины сторон треугольника должны быть заданы числами. Завершение программы.";
    }
    else if (a <= 0 || b <= 0 || c <= 0)
    {
        std::cout << "Значения длин сторон треугольника должны быть больше нуля. Завершение программы.";
    }
    else
    {
        ab = a + b;
        ac = a + c;
        bc = c + b;
        if (ab < c || ac < b || bc < a)
        {
            std::cout << "Такого треугольника не существует.Завершение программы.";
        }
        else
        {
            if (pow(a, 2) + pow(b, 2) > pow(c, 2))
            {
                if (a == b and b == c)
                {
                    std::cout << "Треугольник остроугольный и равносторонний";
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
