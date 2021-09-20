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
        int arr[length] = { a, b, c }; //Введенные значеныя вводим в массив

        for (int i = 0; i < length; ++i) //Перебираем индексы массива
        {
            int smll = i; //Объявляем, что оно наименьшее число
            for (int curr = 0; curr < length; ++curr) //Перебираем индексы массива
            {
                if (arr[smll] < arr[curr]) //Проверяем, если один элемент массива меньше другого, то меняем их местами
                {
                    swap(arr[smll], arr[curr]);
                }
            }
        }
        for (int i = 0; i < length; ++i) //Вводим все обратно в массив
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}