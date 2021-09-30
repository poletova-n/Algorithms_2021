#include <iostream>
#include <cmath>
#include <windows.h>

const char* ERROR_INVALID_START_COEF = "Storony treugol'nika dolzhny byt' zadany celimi chislami, zaversheniye programmy";
const char* ERROR_INVALID_SIZE_LO_ZERO = "Storony treugol'nika dolzhny byt' zadany polozhitel'nymi chislami, zaversheniye programmy";
const char* ERROR_INVALID_TRIANGLE = "Treugol'nik c takimi storonami poluchit' nel'zya, zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N = 0, cmax = 0, amin = 0, bsr = 0, a = 0, b = 0, c = 0;
    try
    {
        std::cin >> a >> b >> c;
        if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
        {
            throw ERROR_INVALID_START_COEF;
        }
        if ((a <= 0) or (b <= 0) or (c <= 0))
        {
            throw ERROR_INVALID_SIZE_LO_ZERO;
        }
        cmax = max(c, max(a, b)); //сторона с максимальной длинной
        amin = min(c, min(a, b)); //сторона с минимальной длинной
        bsr = a + b + c - cmax - amin; //сторона со средней длинной
        if (bsr + amin <= cmax) //проверка на существование треугольника
        {
            throw ERROR_INVALID_TRIANGLE;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }

    if ((cmax == amin) and (amin == bsr))
    {
        std::cout << "Treugol'nik ravnostoronniy";
        exit(0);
    }
    else
        if (pow(cmax, 2) == pow(amin, 2) + pow(bsr, 2)) // проверка на прямоугольный треугольник и.т.д
            std::cout << "Treugol'nik pryamougol'nyy";
        else
            if (pow(cmax, 2) > pow(amin, 2) + pow(bsr, 2))
                std::cout << "Treugol'nik tupougol'nyy";
            else
                if (pow(cmax, 2) < pow(amin, 2) + pow(bsr, 2))
                    std::cout << "Treugol'nik ostrougol'nyy";

    if ((cmax == amin) or (amin == bsr) or (cmax == bsr))
        std::cout << " i ravnobedrennyy";
    return 0;
}
