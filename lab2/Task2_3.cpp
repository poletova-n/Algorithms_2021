#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a = 0, b = 0, c = 0, k = 1;
    std::cout << "Vvedite 3 chisla: ";
    std::cin >> a >> b >> c;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    if (a == b)
    {
        k = 2;
        if (b == c)
            k = 3;
    }
    if (b == c)
    {
        k = 2;
        if (a == c)
            k = 3;
    }
    if (a == c)
    {
        k = 2;
        if (a == b)
            k = 3;
    }
    if (k == 1)
        std::cout << "Net sovpadauchih schisel";
    else
        std::cout << "Kolichestvo sovpadauchih schisel ravno: " << k;
    return 0;
}
