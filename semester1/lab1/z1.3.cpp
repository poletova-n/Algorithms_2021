#include <iostream>
#include <windows.h>
#include <algorithm>

void printTriType(double* sides);

bool allGZ(double* sides);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double sides[] = {0, 0, 0}; // Инициализация переменных для длин сторон
    std::cout << "Введите стороны треугольника: ";
    std::cin >> sides[0] >> sides[1] >> sides[2];
    if(std::cin.fail() || std::cin.peek() != 10 || !allGZ(sides)) // Проверка корректности ввода
    {
        std::cout << "Ошибка: стороны треугольника должны быть заданы положительными числами больше нуля, завершение программы";
    }
    else
    {
        std::sort(std::begin(sides), std::end(sides)); // Сотрировка для нахождения самой большой стороны
        printTriType(sides);
    };
}

void printTriType(double* sides) // Проверка типа треугольника
{
    if(sides[2] >= sides[1] + sides[0])
    {
        std::cout << "Такой треугольник не существует";
    }
    else if(sides[2] == sides[0])
    {
        std::cout << "Треугольник является равносторонним";
    }
    else if(sides[2] == sides[1] || sides[1] == sides[0])
    {
        std::cout << "Треугольник является равнобедренным";
    }
    else if(sides[2]*sides[2] == sides[1]*sides[1] + sides[0]*sides[0])
    {
        std::cout << "Треугольник является прямоугольным";
    }
    else if(sides[2]*sides[2] < sides[1]*sides[1] + sides[0]*sides[0])
    {
        std::cout << "Треугольник является остроугольным";
    }
    else
    {
        std::cout << "Треугольник является тупоугольным";
    }
}

bool allGZ(double* sides)
{
    for (int i = 0; i < 3; ++i)
    {
        if(sides[i] <= 0)
        {
            return false;
        }
    }
    return true;
}



