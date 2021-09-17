#include <iostream>

void compCoords(int* pos1, int* pos2);

int* rC(int* arr);

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
            compCoords(rC(pos1), rC(pos2));
        }
    }
}

void compCoords(int* pos1, int* pos2)
{
    if(pos1[0] == pos2[0] && pos1[1] == pos2[1])
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}

int* rC(int* arr)
{
    for (int i = 0; i < 2; ++i)
    {
        if(arr[i] > 0)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    return arr;
}