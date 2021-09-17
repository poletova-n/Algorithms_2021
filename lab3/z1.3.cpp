#include <iostream>
#include <windows.h>
#include <algorithm>

void printTriType(double* sides);

bool allGZ(double* sides);

const char* ERROR_NOT_VALID_INPUT = "Ошибка: стороны треугольника должны быть заданы положительными числами больше нуля, завершение программы";
const char* ERROR_TRIG_NOT_EXISTS = "Ошибка: такой треугольник не существует!";


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        double sides[] = {0, 0, 0}; // Инициализация переменных для длин сторон
        std::cout << "Введите стороны треугольника: ";
        std::cin >> sides[0] >> sides[1] >> sides[2];
        if (std::cin.fail() || std::cin.peek() != 10 || !allGZ(sides)) // Проверка корректности ввода
        {
            throw ERROR_NOT_VALID_INPUT;
        }
        else
        {
            std::sort(std::begin(sides), std::end(sides)); // Сотрировка для нахождения самой большой стороны
            if(sides[2] >= sides[1] + sides[0])
            {
                throw ERROR_TRIG_NOT_EXISTS;
            }
            printTriType(sides);
        };
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

void printTriType(double* sides) // Проверка типа треугольника
{
    if(sides[2] == sides[0])
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

