#include <iostream>

int main()
{
    int pos1[2] = {0, 0};
    int pos2[2] = {0, 0};
    std::cout << "First position: ";
    std::cin >> pos1[0] >> pos1[1];
    if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
    {
        std::cout << "Error: position must only contain numbers"; // Если ввод неверный
    }
    else
    {
        std::cout << "Second position: ";
        std::cin >> pos2[0] >> pos2[1];
        if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
        {
            std::cout << "Error: position must only contain numbers"; // Если ввод неверный
        }
        else
        {
            if(pos1[0]* pos2[0] > 0 && pos1[1] * pos2[1] > 0)
            {
                std::cout << "YES";
            }
            else
            {
                std::cout << "NO";
            }
        }
    }
}