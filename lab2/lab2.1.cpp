#include <iostream>
using namespace std;
int main() {
    while (1) {

        setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

        // Ввод значения

        int god;

        cout << "Введите 1 число - номер года (Можно использовать только целые неотрицательные числа)" << endl;

        // Проверка чисел

        if (cin >> god) {

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

        if (god < 0) {
            cout << "Можно использовать только целые неотрицательные числа - Вы ввели отрицательное число";
            return 1;
        }

        // решение задачи

        if ((god % 4 == 0 and god % 100 != 0) or (god % 100 == 0 and god % 400 == 0)) {
            cout << god << " год високосный" << endl;
        }
        else {
            cout << god << " год не високосный" << endl;
        }
    }
    return 0;
}