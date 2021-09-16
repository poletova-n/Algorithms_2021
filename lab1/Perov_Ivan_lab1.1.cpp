#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Ввод 3 значений

    int voroni;

    cout << "Введите 1 число - количество ворон (Можно использовать только целые неотрицательные числа)" << endl;

    // Проверка чисел

    if (cin >> voroni) {

        if (cin.peek() == EOF or cin.peek() == '\n')
        {

        }
        else
        {

            cout << endl << "Можно использовать только целые неотрицательные числа - Вы ввели нецелое число " << endl;
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

    // Проверка на неотрицательность

    if ((voroni < 0)) {
        cout << "Можно использовать только целые неотрицательные числа - Вы ввели отрицательное число";
        return 1;
    }

    if (voroni % 10 == 1 and voroni != 11) {
        cout << "В стае " << voroni << " ворона";
    }

    else if ((voroni % 10 == 2 or voroni % 10 == 3 or voroni % 10 == 4) and voroni != 12 and voroni != 13 and voroni != 14) {
        cout << "В стае" << voroni << " вороны";
    }

    else {
        cout << "В стае " << voroni << " ворон";
    }

    return 0;
}