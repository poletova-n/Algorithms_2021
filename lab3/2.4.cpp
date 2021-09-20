#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа";
const string ERROR_NOT_POSITIVE_NUMBER = "Вводить можно только положительные числа";
const string ERROR_LIMIT_BOARD = "Доска в масштабе 8х8, нельзя вводить числа больше 8";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        int a, b, c, d; //Объявляем переменные

        cout << "Введите координаты ферзя и координаты другой фигуры: ";
        cin >> a >> b >> c >> d; //Вводим переменные

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        if ((a < 1 || b < 1 || c < 1 || d < 1) || (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
        {
            throw ERROR_LIMIT_BOARD;
        }
        else
        {
            if (a == c || b == d || abs(a - c) == abs(b - d)) //Проверяем, может ли ферзь съесть данную фигуру
            {
                cout << "Да!";
            }
            else
            {
                cout << "Нет!";
            }
            return 0;
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}