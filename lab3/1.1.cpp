#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа!";
const string ERROR_NOT_QUADRATIC_EQUATION = "Вы ввели не квадратное уравнение!";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        cout << "Введите переменные a b c: ";

        double a, b, c, x1, x2;

        cin >> a >> b >> c;

        if (cin.fail() || cin.peek() != 10)
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a == 0 || b == 0 || c == 0)
        {
            throw ERROR_NOT_QUADRATIC_EQUATION;
        }
        else
        {
            cout << "Первая переменная: " << a << endl << " Вторая переменная: " << b << endl << " Третья переменная: " << c << endl;

            double disc = (b * b) - (4 * a * c);

            double sqrtD = sqrt(disc);

            if (disc < 0)
            {
                cout << "Нет корней" << endl;
                return 0;
            }

            if ((sqrtD * sqrtD) == disc)
            {
                if (disc == 0)
                {
                    x1 = (-b) / (2 * a);
                    cout << " Один корень: " << x1 << endl;
                }
                else
                {
                    x1 = (-b + sqrtD) / (2 * a);
                    x2 = (-b - sqrtD) / (2 * a);
                    cout << " Первый корень: " << x1 << endl;
                    cout << " Второй корень: " << x2 << endl;
                }
            }
            else
            {
                cout << "Дискриминант не выводится из под корня!";
            }
        }
        return 0;
    }
    catch(const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }

}