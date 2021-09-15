#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N;
    std::cout << "Введите количество ворон в стае" << std::endl;
    std::cin >> N;
    if (std::cin.peek() != '\n')
    {
        std::cout << "Значение должно быть задано числом. Завершение программы.";
    }
    else
    {
        if (N <= 0)
        {
            std::cout << "Значение должно быть больше нуля и не равно ему. Завершение программы.";
        }
        else
        {

            if (N % 10 == 1)
            {
                std::cout << "В стае" << " " << N << " " << "ворона";
            }
            else if (N % 10 == 2 || N % 10 == 3 || N % 10 == 4)
            {
                std::cout << "В стае" << " " << N << " " << "вороны";
            }
            else
            {
                std::cout << "В стае" << " " << N << " "<< "ворон";
            }
        }
    }
    retuen 0;
}


