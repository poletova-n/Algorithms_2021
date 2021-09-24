#include <iostream>
#include <windows.h>

const char* ERROR_NOT_NUMBER = "Ошибка: вы ввели не число!";
const char* ERROR_EMPTY_STRING = "Ошибка: вы ничего не ввели!";

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    try
    {
        int n = 0, count = -1, max = 0;
        while(1)
        {
            std::cout << "Введите любое натуральное число или 0 чтобы закончить: ";
            std::cin >> n;
            std::cout << std::endl;
            if (std::cin.fail() || std::cin.peek() != 10)
            {
                throw ERROR_NOT_NUMBER;
            }
            if (n == 0)
            {
                break;
            }
            if(n > max)
            {
                max = n;
                count++;
            }
        }
        if (count == -1)
        {
            throw ERROR_EMPTY_STRING;
        }
        else
        {
            std::cout << count << " - количество чисел больше предыдущего";
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
    return 0;
}


