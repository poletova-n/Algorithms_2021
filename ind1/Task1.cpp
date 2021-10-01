#include <iostream>
#include <cmath>
#include <windows.h>

const char* ERROR_INVALID_START_COEF = "Na vhod dolzhny byt' zadany celimi chislami, zaversheniye programmy";
const char* ERROR_LITTLE_SIZE = "Kolichestvo chlenov v posledovatel'nosti men'she 3-yeh, zaversheniye programmy";
const char* ERROR_EMPTY_SEQUENCE = "Vvedena pustaya posledovatel'nost', zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n = 0, sum = 0, k = 1, a = 0, b = 0, c = 0, quantity = 0;
    try
    {
        std::cin >> n;
        if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
        {
            throw ERROR_INVALID_START_COEF;
        }

        if (n == 0)
        {
            throw ERROR_EMPTY_SEQUENCE;
        }
        while (n != 0)
        {
            c = b;
            b = a;
            a = n;
            if ((pow(a, 2) == pow(b, 2) + pow(c, 2)) and (a != 0) and (b != 0) and (c != 0))
            {
                quantity++;
            }
            std::cin >> n;
            if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
            {
                throw ERROR_INVALID_START_COEF;
            }
            if ((k < 3) and (n == 0))
            {
                throw ERROR_LITTLE_SIZE;
            }
            if (n != 0)
            {
                k++;
            }


        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }
    std::cout << "Kolichestvo pifagorovykh troyek ravno: " << quantity;
}

