#include <iostream>
#include <cmath>
#include <windows.h>

const char* ERROR_INVALID_START_COEF = "Vvedeno ne chislo, ili nekotorie is chisel ne celie, zavershenie programmi";
const char* ERROR_INVALID_DISC_COEF = "Iz diskriminanta ne izvlekayetsya tseloye chislo!";
const char* ERROR_INVALID_DISC_LO_ZERO = "Korney net, tak kak diskriminant men'she nulya";
const char* ERROR_NOT_QUADRATIC_EQUATION = "Pervyy vvedennyy koeffitsiyent raven 0, eto ne kvadratnoye uravneniye, zaversheniye programmy";
const char* ERROR_WHOLE_ROOTS = "Poluchennyye korni uravneniya ne yavlyayutsya tselymi chislami, zaversheniye programmy";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double x1 = 0.0, x2 = 0.0;
    int D = 0, i = 0, k = 0;
    int a = 0, b = 0, c = 0; //значения в типе int
    try
    {
        std::cin >> a >> b >> c;
        if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
        {
            throw ERROR_INVALID_START_COEF;
        }
        if (a == 0)
        {
            throw ERROR_NOT_QUADRATIC_EQUATION;
        }
        D = pow(int(b), 2) - 4 * a * c;
        if (int(sqrt(D)) != float(sqrt(D))) // проверка на извлечение целого числа из под корня
        {
            throw ERROR_INVALID_DISC_COEF;
        }
        if (D < 0)
        {
            throw ERROR_INVALID_DISC_LO_ZERO;
        }
        x1 = float(-b + sqrt(D)) / (2 * a);
        x2 = float(-b - sqrt(D)) / (2 * a);
        if ((int(x1) != float(x1)) or (int(x2) != float(x2)))
        {
            throw ERROR_WHOLE_ROOTS;
        }
    }
    catch (const char* error)
    {
        std::cerr << error;
        return 1;
    }
    if (x1 == x2) // проверка на совпавшие корни
    {
        std::cout << "Koren: " << x1;
    }
    else
    {
        std::cout << "Pervyy koren: " << x1 << std::endl << "Vtoroy koren: " << x2;
    }
    return 0;
}