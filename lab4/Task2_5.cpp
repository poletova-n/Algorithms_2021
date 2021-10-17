#include <iostream>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N = 0, i = 0, j = 0, zero = 0;
    std::cout << "Enter the side of the rhombus: ";
    std::cin >> N;
    zero = N - 1;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "The side of the rhombus must be number";
        exit(0);
    }
    if (N <= 0)
    {
        std::cout << "The side of the rhombus must be greatest than zero";
        exit(0);
    }
    std::cout << std::endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < zero; j++)
        {
            std::cout << " ";
        }
        for (j = 0; j < i + 1; j++)
        {
            std::cout << "* ";
        }
        zero--;
        std::cout << std::endl;
    }
    zero = 0;
    for (i = N; i > 0; i--)
    {
        for (j = 0; j < zero + 1; j++)
        {
            std::cout << " ";
        }
        for (j = 1; j < i; j++)
        {
            std::cout << "* ";
        }
        zero++;
        std::cout << std::endl;
    }
    return 0;
}