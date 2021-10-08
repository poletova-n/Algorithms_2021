#include <iostream>
#include <cmath>
#include <windows.h>
#include <climits>

const char* ERROR_INVALID_START_COEF = "Na vhod dolzhny byt' zadany celimi chislami, zaversheniye programmy";
const char* ERROR_EMPTY_SEQUENCE = "Vvedena pustaya posledovatel'nost', zaversheniye programmy";
const char* ERROR_NO_POSITIVE_NUMBERS = "V vvedenoy posledovatel'nosti net polozhitel'nykh chisel, zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n = 0, k = 1, minn = INT_MAX, mink = 0;
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
            if (n < minn)
            {
                if (n > 0)
                {
                    minn = min(minn, n);
                    mink = k;
                }
            }
            std::cin >> n;
            if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
            {
                throw ERROR_INVALID_START_COEF;
            }
            if (n != 0)
            {
                k++;
            }
        }
        if (minn == INT_MAX)
        {
            throw ERROR_NO_POSITIVE_NUMBERS;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }
    std::cout << "Minimal'nyy pologitelnii chlen posledovatel'nosti raven: " << minn << "\nPoryadkovyy nomer minimal'nnogo pologitelnogo chlena raven: " << mink;
}