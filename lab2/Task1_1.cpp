include <iostream>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N = 0;
    std::cout << "Vvedite god:\n 20";
    std::cin >> N;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "Na vhod v programmu dolgni podavatsia tolko hisla";
        exit(0);
    }
    else if (N < 0)
    {
        std::cout << "Bilo vvedeno oitecatelnoe chislo, zavershenie programmi";
        exit(0);
    }
    if (((N % 4 == 0) and (N % 100 != 0)) or (N % 400 == 0))
    {
        std::cout << "God visokosnyy";
    }
    else
    {
        std::cout << "God ne visokosnyy";
    }
    return 0;
}
