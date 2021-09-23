#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int a = 0, b = 0, c = 0;
    std::cout << "Vvedite 3 chisla: ";
    std::cin >> a >> b >> c;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko chisla";
        exit(0);
    }
    std::cout << "Chisla v poryadke neubivania: " << min(a, min(b, c)) << " " << (a + b + c) - max(max(a, b), c) - min(a, min(b, c)) << " " << max(max(a, b), c);
    return 0;
}
