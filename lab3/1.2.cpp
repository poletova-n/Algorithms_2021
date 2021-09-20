#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа!";
const string ERROR_NOT_POSITIVE_NUMBER = "Вводить можно только положительные числа!";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        int n = 0; //Объявляем переменную

        cout << "Введите количество ворон: ";
        cin >> n; //Вводим переменную

        if (cin.fail() || cin.peek() != 10) //Проверяем, является ли переменная числом
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (n < 0) //Проверяем, является ли переменная положительным числом
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else
        {
            if (n % 10 == 1 && n % 100 != 11) //Если число оканчивается на 1, но не 11, то окончание будет "а"
            {
                cout << "В стае " << n << " ворона";
            }
            else if ((n % 10 >= 2 && n % 10 <= 4)) //Если число оканчивается на числа от 5 до 20, то окончание будет нулевое
            {
                cout << "В стае " << n << " вороны";
            }
            else //В остальных случаях окончание не будет
            {
                cout << "В стае " << n << " ворон";
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }

}