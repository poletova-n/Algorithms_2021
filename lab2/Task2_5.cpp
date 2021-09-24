#include <iostream>
#include <windows.h>

int chet(int a, int b)
{
    if ((a > 0) and (b > 0))
        return 1;
    if ((a > 0) and (b < 0))
        return 4;
    if ((a < 0) and (b > 0))
        return 2;
    if ((a < 0) and (b < 0))
        return 3;
    return 0;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int X1 = 0, X2 = 0, Y1 = 0, Y2 = 0;
    std::cout << "Vvedite koordinati pervoi tochki: ";
    std::cin >> X1 >> Y1;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    std::cout << "Vvedite koordinati vtoroi tochki: ";
    std::cin >> X2 >> Y2;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    if ((chet(X1, Y1) == chet(X2, Y2)) and (chet(X1, Y1) != 0) and (chet(X2, Y2) != 0))
        std::cout << "YES";
    else
        std::cout << "NO";

    return 0;
}
