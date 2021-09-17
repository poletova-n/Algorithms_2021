#include <iostream>

void isBeats(int* lad, int* other);

int main()
{
    int lad[2] = {0,0}, other[2] = {0,0};
    std::cout << "Enter coordinates of bishop: ";
    std::cin >> lad[0] >> lad[1];
    if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
    {
        std::cout << "Error: coordinates must only contain numbers"; // Если ввод неверный
    }
    else
    {
        std::cout << "Enter coordinates of piece: ";
        std::cin >> other[0] >> other[1];
        if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
        {
            std::cout << "Error: coordinates must only contain numbers"; // Если ввод неверный
        }
        else
        {
            isBeats(lad, other);
        }
    }
}

void isBeats(int* lad, int* other)
{
    if(abs(lad[0] - other[0]) == abs(lad[1] - other[1]))
    {
       std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
};