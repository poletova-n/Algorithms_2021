#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c; //Объявляем переменные

    cout << "Введите три числа: ";
    cin >> a >> b >> c; //Вводим значения

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else
    {
        const int length = 3; //Объявляем длину массива
        int arr[length] = { a, b, c };
        int count = 0;

        for (int i= 0; i < length; i++) //Устанавливаем цикл, которые будет перебирать все значения массива
        {
            for (int j = 1; j < length-1; j++) //устанавливаем цикл, который будет искать одинаковые значения
            {
                if (arr[i] == arr[j + i])
                {
                    count += 1;
                }
            }
        }
        cout << "Совпадений в массиве: " << count;
    }
    return 0;
}
