#include <iostream>
#include <windows.h>

bool chet(int a)
{
    if (a % 2 == 0)
        return 0;
    else
        return 1;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a = 0, b = 0, c = 0, k = 0;
    std::cout << "Vvedite 3 chisla: ";
    std::cin >> a >> b >> c;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    k = a % 2 + b % 2 + c % 2;
    if ((k == 1) or (k == 2))
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
