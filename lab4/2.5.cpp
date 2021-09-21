#include <iostream>
#include <windows.h>
#include <string>

const std::string ERROR_NOT_NUMBER = "You entered not the number";
const std::string ERROR_NOT_POSITIVE_NUMBER = "You entered not positive number";

int main()
{
    try
    {
        int n,i,j,q;
        std::cout << "Enter the number: ";
        std::cin >> n;

        if (std::cin.fail() || std:: cin.peek() != 10)
        {
            throw ERROR_NOT_NUMBER;
        }
        if (n < 0)
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else
        {
            int space = n - 1;
            for (int i = 0; i < n; i++) // запустить цикл до количества строк
            {
                std::cout << std::endl;
                for (int j = 0;j < space; j++) // цикл для изначально пространства, до начала печати
                {
                    std::cout << " ";
                }
                for (int j = 0; j <= i; j++) // Печать i + 1 звезд
                {
                    std::cout << "* ";
                }

                space--;
            }
            space = 0; // Повторить снова в обратном порядке
            for (int i = n; i > 0; i--) // запустить цикл до количества строк
            {
                std::cout << std::endl;
                for (int j = 0; j < space; j++) // цикл для изначально пространства, до начала печати
                {
                    std::cout << " ";
                }
                for (int j = 0;j < i;j++) // Печать я звезды
                {
                    std::cout << "* ";
                }
                space++;
            }
        }
    }
    catch (const std::string& error)
    {
        std::cerr << std::endl << error << std:: endl;
        return -1;
    }
}
