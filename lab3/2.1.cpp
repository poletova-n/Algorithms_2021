#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа";
const string ERROR_NOT_POSITIVE_NUMBER = "Вводить можно только положительные числа";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        int a; //Объявляем переменную

        cout << "Введите год: ";

        cin >> a; //Вводим значение

        if (cin.fail() || cin.peek() != 10) //Проверяем является ли значение числом
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a < 0) //Проверяем является ли значение положительным числом
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else
        {
            if (a % 4 == 0) //Проверяем кратен ли год четырем
            {
                if (a % 100 != 0) //Если да, то роверяем кратен ли год ста
                {
                    cout << "Год " << a << " високосный" << endl;
                }
                else //Иначе
                {
                    if (a % 400 == 0) //Проверям кратен ли год четырестам
                    {
                        cout << "Год " << a << " високосный" << endl;
                    }
                    else //Если нет, то
                    {
                        cout << "Год " << a << " обычный" << endl;
                    }
                }
            }
            else //Если нет, то
            {
                cout << "Год " << a << " обычный" << endl;
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}