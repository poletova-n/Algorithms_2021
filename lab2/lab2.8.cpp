#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Ввод значения
    int a;
    int b;
    int c;
    cout << "Введите 3 числа (Можно использовать только целые числа )" << endl;

    // Проверка чисел

    if (cin >> a >> b >> c) {

        if (cin.peek() == EOF or cin.peek() == '\n')
        {

        }
        else
        {

            cout << endl << "Можно использовать только целые неотрицательные числа - Вы ввели нецелое число или болььше чисел чем нужно45" << endl;
            cin.ignore(100, '\n');
            cin.clear();
            return 1;

        }
    }
    else
    {
        cin.ignore(100, '\n');
        cin.clear();
        cout << "Можно использовать только целые неотрицательные числа - Вы ввели символы";
        return 1;

    }
    
    if ((a == b) and (a == c) and (b == c)) {
        cout << "3 числа совпадают";
    }
    else if ((a == b) or (a == c) or (b == c)) {
        cout << "2 числа совпадают";
    }
    else {
        cout << "Нет совпадающих чисел";
    }
    return 0;
}