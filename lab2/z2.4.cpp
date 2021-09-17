#include <iostream>

void isOk(int* arr);

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
        isOk(input);
    }
}

void isOk(int* arr)
{
    bool c = false, nc = false;
    for (int i = 0; i < 3; ++i)
    {
        if(arr[i]%2 == 0)
        {
            c = true;
        }
        else
        {
            nc = true;
        }
    }
    if(c && nc)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}