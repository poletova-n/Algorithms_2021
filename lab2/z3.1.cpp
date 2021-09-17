#include <iostream>

void toRom(int year);

int main()
{
    int year = 0;
    std::cout << "Enter year: ";
    std::cin >> year;
    if(std::cin.fail() || std::cin.peek() != 10 || year < 400) // Проверка корректности ввода
    {
        std::cout << "Error: year must only contain numbers and be more than 400"; // Если ввод неверный
    }
    else
    {
        toRom(year);
    }
}

void toRom(int year){
    char symb[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    short del = 5000;
    std::cout << "Result: ";
    for (int i = 7; i > 0; i--) {
        if(i%2 == 1)
        {
            del /= 5;
        }
        else
        {
            del /= 2;
        }
        for (int j = 0; j < year/del; ++j)
        {
            std::cout << symb[7 - i];
        }
        year = year%del;
    }
}