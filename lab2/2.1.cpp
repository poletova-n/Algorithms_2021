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
        int arr[3] = { a, b, c };
        int max = arr[0];


        for (int x = 0; x < sizeof(arr); x++) //Устанавливаем цикл, которые будет перебирать все значения массива
        {
            if (arr[x] > max) //Создаем условие, если перебираемое число будет больше значения max, то присваеваем наибольшее число в переменную max
            {
                max = arr[x];
            }
        }
        cout << max << endl;
    }
    return 0;
}
