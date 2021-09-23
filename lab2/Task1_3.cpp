#include <iostream>
#include <windows.h>

bool Ist(int a) //проверка на то, что введеные значения находятся на игральной доске
{
    if ((a > 0) and (a < 9))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int X1 = 0, X2 = 0, Y1 = 0, Y2 = 0;
    std::cout << "Vvedite gde stoit slon: ";
    std::cin >> X1 >> Y1;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    std::cout << "Vvedite gde stoit figura: ";
    std::cin >> X2 >> Y2;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    if (!(Ist(X1) and Ist(X2) and Ist(Y1) and Ist(Y2)))
    {
        std::cout << "Vvedenie znachenia ne dolgni vihodit za predeli igralnoi doski ili bit otrocatelnimi";
        exit(0);
    }
    if ((X1 - X2 == Y1 - Y2))
    {
        std::cout << "Figura budet siedena";
    }
    else
    {
        std::cout << "Slon ne smoget siest figuru";
    }
    return 0;
}
