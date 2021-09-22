#include <iostream>
#include <windows.h>

const char* error_value_not_number = "Значение должно быть задано числом. Завершение программы.";
const char* error_value_zero = "Значение должно быть больше нуля и не равно ему. Завершение программы.";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int N;
    try
    {
        std::cout << "Введите количество ворон в стае" << std::endl;
        std::cin >> N;
        if (std::cin.peek() != '\n')
        {
            throw error_value_not_number;
        }
        if (N <= 0)
        {
            throw error_value_zero;
        }
        else
        {
            if (N % 10 == 1 and N % 100 != 11)
            {
                std::cout << "В стае" << " " << N << " " << "ворона";
            }
            if (N % 10 == 2 || N % 10 == 3 || N % 10 == 4)
            {
                std::cout << "В стае" << " " << N << " " << "вороны";
            }
            else if (N % 100 == 11)
            {
                std::cout << "В стае" << " " << N << " " << "ворон";
            }
            else
            {
                std::cout << "В стае" << " " << N << " " << "ворон";
            }
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}


