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





#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "Вводить можно только числа!";
const string ERROR_NOT_POSITIVE_NUMBER = "Вводить можно только положительные числа!";
const string ERROR_NOT_TRIANGLE = "Такого треугольника не существует!";

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    try
    {
        double a, b, c; //Вводим переменные

        cout << "Введите стороны треугольника: ";

        cin >> a >> b >> c; //Вводим значения

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a < 0 || b < 0 || c < 0) //Проверям, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else if (a > b + c || b > a + c || c > a + b)
        {
            throw ERROR_NOT_TRIANGLE;
        }
        else
        {
            cout << "a: " << a << endl << " b: " << b << endl << " c: " << c;
            if (a == b && a == c && b == c) //Если все стороны равны, то треугольник равностороний
            {
                cout << endl << "Треугольник: равностороний";
            }
            else if (a == b && a == c && b == c) //Если две боковые стороны равны, то треугольник равнобедренный
            {
                cout << endl << "Треугольник: равнобедренный";
            }
            else if (pow(c, 2) == pow(a, 2) + pow(b, 2)) //Если квадрат стороны С равен сумме квадратов сторон А и В, то треугольник равностороний
            {
                cout << endl << "Треугольник: прямоугольный";
            }
            else if (pow(c, 2) < pow(a, 2) + pow(b, 2)) //Если квадрат стороны С меньше сумме квадратов сторон А и В, то треугольник равностороний
            {
                cout << endl << "Треугольник: остроугольный";
            }
            else
            {
                cout << endl << "Треугольник: тупоугольный";
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}


//ладья
#include <iostream>
#include <windows.h>
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

        cout << "Введите координаты ладьи и координаты другой фигуры: ";
        cin >> a >> b >> c >> d; //Вводим переменные

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else if ((a < 1 || b < 1 || c < 1 || d < 1) || (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур корректными
        {
            throw ERROR_LIMIT_BOARD;
        }
        else
        {
            if ((a == c && b != d) || (a != c && b == d)) //Проверяем, может ли ладья съесть данную фигуру
            {
                cout << "Да!" << endl;
            }
            else
            {
                cout << "Нет!" << endl;
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}


//конь
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

        cout << "Введите координаты коня и координаты другой фигуры: ";
        cin >> a >> b >> c >> d; //Вводим переменные

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else if ((a < 1 || b < 1 || c < 1 || d < 1) || (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
        {
            throw ERROR_LIMIT_BOARD;
        }
        else
        {
            if ((abs(a - c) == 1 && abs(b - d) == 2) || (abs(a - c) == 2 && abs(b - d) == 1)) //Проверяем, может ли конь съесть данную фигуру
            {
                cout << "Да!";
            }
            else
            {
                cout << "Нет!";
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}




//ферзь
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


//Год
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



//слон
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

        cout << "Введите координаты слона и координаты другой фигуры: ";
        cin >> a >> b >> c >> d; //Вводим переменные

        if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
        {
            throw ERROR_NOT_NUMBER;
        }
        if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        if ((a < 1 || b < 1 || c < 1 || d < 1) || (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур корректными
        {
            throw ERROR_LIMIT_BOARD;
        }
        else
        {
            if (abs(a-c) == abs(b-d)) //Проверяем, может ли слон съесть данную фигуру
            {
                cout << "Да!" << endl;
            }
            else
            {
                cout << "Нет!" << endl;
            }
        }
    }
    catch (const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}