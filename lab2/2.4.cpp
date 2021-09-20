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
        int arr[length] = { a, b, c}; //Вводим заданные значения в массив
        string answer = "НЕТ";

        for (int i = 0; i < length; i++) //Цикл для изменения индекса массива
        {
            for (int j = 0; j < length+1; j++) //Второй цикл для изменения индекса массива
            {
                if (arr[i] % 2 == 0 && arr[j] % 2 != 0) //Если в массиве есть хотябы одно четное и нечетное число, то отвечаем да
                {
                    answer = "ДА";
                }
            }
        }
        cout << answer; //Если в цикле условие не выполняется, то ответ будет "НЕТ"
    }
    return 0;
}