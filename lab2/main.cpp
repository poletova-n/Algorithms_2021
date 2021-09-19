//сортировка
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



//ладья
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c, d; //Объявляем переменные

    cout << "Введите координаты ладьи и координаты другой фигуры ";
    cin >> a >> b >> c >> d; //Вводим переменные

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
    {
        cout << "Вводить можно только положительные числа" << endl;
    }
    else if ((a < 1 || b < 1 || c < 1 || d < 1) && (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
    {
        cout << "Доска в масштабе 8х8, нельзя вводить числа больше 8 и меньше 1" << endl;
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


//конь
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c, d; //Объявляем переменные

    cout << "Введите координаты коня и координаты другой фигуры ";
    cin >> a >> b >> c >> d; //Вводим переменные

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
    {
        cout << "Вводить можно только положительные числа" << endl;
    }
    else if ((a < 1 || b < 1 || c < 1 || d < 1) && (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
    {
        cout << "Доска в маштабе 8х8, нельзя вводить числа больше 8 и меньше 1" << endl;
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




//ферзь
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c, d; //Объявляем переменные

    cout << "Введите координаты ферзя и координаты другой фигуры ";
    cin >> a >> b >> c >> d; //Вводим переменные

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
    {
        cout << "Вводить можно только положительные числа" << endl;
    }
    else if ((a < 1 || b < 1 || c < 1 || d < 1) && (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
    {
        cout << "Доска в маштабе 8х8, нельзя вводить числа больше 8 и меньше 1" << endl;
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

//четное нечетное
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




//координаты
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int x1, y1, x2, y2; //Объявляем переменные

    cout << "Введите координаты первой и второй точки (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2; //Вводим значения

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else
    {
        if ((x1 > 0 && y1 > 0) && (x2 > 0 && y2 > 0)) //Если координаты первой точки положительные и координаты второй положительны, то они находятся на одной плоскости
        {
            cout << "Обе точки находятся в 1-ой четверти";
        }
        else if ((x1 < 0 && y1 > 0) && (x2 < 0 && y2 > 0)) //Если координаты первой точки, первая координата отрицательная, а вторая положительная и анологична со вторыми координатами, то они тоже находятся на одной плоскости
        {
            cout << "Обе точки находятся во 2-ой четверти";
        }
        else if ((x1 < 0 && y1 < 0) && (x2 < 0 && y2 < 0)) //Если координаты первой точки, первая координата отрицательная, и вторая отрицательная и анологична со вторыми координатами, то они тоже находятся на одной плоскости
        {
            cout << "Обе точки находятся в 3-ей четверти";
        }
        else if ((x1 > 0 && y1 < 0) && (x2 > 0 && y2 < 0)) //Если координаты первой точки, первая координата положительная, а вторая отрицательная и анологична со вторыми координатами, то они тоже находятся на одной плоскости
        {
            cout << "Обе точки находятся в 4-ой четверти";
        }
        else if (x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0) //Проверяем, нет ли среди координаты нуля
        {
            cout << "Вводить можно любые координаты, кроме 0";
        }
        else //В других остальных случаях точки расположенны на разных плоскостях
        {
            cout << "Точки находятся на разных четвертях";
        }
    }
    return 0;
}




//макс число
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





//совпадение
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



//Год
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a; //Объявляем переменную

    cout << "Введите год: ";

    cin >> a; //Вводим значение

    if (cin.fail() || cin.peek() != 10) //Проверяем является ли значение числом
    {
        cout << "Вводить можно только числа!";
    }
    else if (a < 0) //Проверяем является ли значение положительным числом
    {
        cout << "Вводить можно только положительные числа!";
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



//слон
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a, b, c, d; //Объявляем переменные

    cout << "Введите координаты слона и координаты другой фигуры ";
    cin >> a >> b >> c >> d; //Вводим переменные

    if (cin.fail() || cin.peek() != 10) //Проверяем, являются ли переменные числами
    {
        cout << "Вводить можно только числа" << endl;
    }
    else if (a < 0 || b < 0 || c < 0 || d < 0) //Проверяем, являются ли переменные положительными числами
    {
        cout << "Вводить можно только положительные числа" << endl;
    }
    else if ((a < 1 || b < 1 || c < 1 || d < 1) && (a > 8 || b > 8 || c > 8 || d > 8)) //Проверяем, являются ли координаты фигур коректными
    {
        cout << "Доска в маштабе 8х8, нельзя вводить числа больше 8 и меньше 1" << endl;
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


