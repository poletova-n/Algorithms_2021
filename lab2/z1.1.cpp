#include <iostream>

int main()
{
    int year = 0;
    std::cout << "Enter year: ";
    std::cin >> year;
    if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
    {
        std::cout << "Error: year must only contain numbers"; // Если ввод неверный
    }
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
    {
        std::cout << "This year is a leap year";
    }
    else
    {
        std::cout << "This year isn't a leap year";
    }
}

