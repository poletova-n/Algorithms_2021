#include <iostream>
#include <algorithm>

int main()
{
    int input[3] = {0,0,0};
    std::cout << "Enter numbers: ";
    std::cin >> input[0] >> input[1] >> input[2];
    if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
    {
        std::cout << "Error: input must only contain numbers"; // Если ввод неверный
    }
    else
    {
        std::sort(std::begin(input), std::end(input));
        std::cout << "Sorted numbers: " << input[0] << " " << input[1] << " " << input[2];
    }
}
