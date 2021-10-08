#include <iostream>
#include <cmath>
#include <windows.h>

const char* ERROR_INVALID_START_COEF = "Na vhod dolzhny byt' zadany celimi chislami, zaversheniye programmy";
const char* ERROR_EMPTY_SEQUENCE = "Vvedena pustaya posledovatel'nost', zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n = 0, k = 1, a = 0, b = 0, c = 0;
    float sum = 0.0;
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
            sum += n;
            std::cin >> n;
            if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
            {
                throw ERROR_INVALID_START_COEF;
            }
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }
    std::cout << "Summa chisel ravna: " << sum;
}

