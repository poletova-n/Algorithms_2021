#include <iostream>

int repNum(int* arr);

int main()
{
    int input[3] = {0, 0, 0};
    std::cout << "Enter numbers: ";
    std::cin >> input[0] >> input[1] >> input[2];
    if(std::cin.fail() || std::cin.peek() != 10) // Проверка корректности ввода
    {
        std::cout << "Error: input must only contain numbers"; // Если ввод неверный
    }
    else
    {
        std::cout << "There are " << repNum(input) << " matching numbers here" ;
    }
}

int repNum(int* arr)
{
    int c = 0;
    if(arr[0] == arr[1])
    {
        c++;
    }
    if(arr[1] == arr[2])
    {
        c++;
    }
    if(arr[0] == arr[2])
    {
        c++;
    }
    return c;
}