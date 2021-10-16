#include <iostream>
using namespace std;
const char* ERROR_NOT_INTEGER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NOT_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NEGATIVE_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели отрицательные числа";
int main() {
    try {
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

                throw ERROR_NOT_INTEGER;
                cin.ignore(100, '\n');
                cin.clear();
                return 1;

            }
        }
        else
        {
            cin.ignore(100, '\n');
            cin.clear();
            throw  ERROR_NOT_NUMBER;
            return 1;

        }

        // Проверка на неотрицательность

        if ((voroni < 0)) {
            throw ERROR_NEGATIVE_NUMBER;
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
    }
    catch (const char* error) {
        cerr << endl << error << endl;
    }
    return 0;
}