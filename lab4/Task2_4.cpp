#include <iostream>
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N = 0, i = 0, j = 0;
    std::cout << "Enter the side of the triangle: ";
    std::cin >> N;
    if ((std::cin.fail()) or (std::cin.peek() != 10))
    {
        std::cout << "The side of the triangle must be number";
        exit(0);
    }
    if (N <= 0)
    {
        std::cout << "The side of the triangle must be greatest than zero";
        exit(0);
    }
    for (i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (j = 0; j < i + 1; j++)
        {
            std::cout << "* ";
        }
    }
    return 0;
}