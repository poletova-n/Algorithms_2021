#include <iostream>
#include <cmath>
#include <windows.h>

const char* ERROR_INVALID_START_COEF = "Chislo voron v staye dolzhno byt' zadano celim chislom, zaversheniye programmy";
const char* ERROR_INVALID_N_LO_ZERO = "Chislo voron dolzhno byt' zadano polozhitel'nym chislom, zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x1 = 0.0, x2 = 0.0;
    int N = 0;
    try
    {
        std::cin >> N;
        if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
        {
            throw ERROR_INVALID_START_COEF;
        }
        if (N <= 0)
        {
            throw ERROR_INVALID_N_LO_ZERO;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }
    if (((N >= 5) and (N <= 20)) or (N % 10 == 0) or (N % 10 == 5) or (N % 10 == 6) or (N % 10 == 7) or (N % 10 == 8) or (N % 10 == 9))
    {
        std::cout << "V stae " << N << " voron";
        exit(0);
    }
    if ((N % 10 == 2) or (N % 10 == 3) or (N % 10 == 4)) //выбор выводимого текста исходя из введёных значений
    {
        std::cout << "V stae " << N << " voroni";
        exit(0);
    }
    if (N % 10 == 1)
    {
        std::cout << "V stae " << N << " vorona";
    }
    return 0;
}
