#include <iostream>
using namespace std;

const char* ERROR_NOT_INTEGER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NOT_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NEGATIVE_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели отрицательные числа";
const char* ERROR_NOT_EXIST = "Такой треугольник не существует";


int main() {
    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);
    try {

        // Ввод 3 значений

        int a;
        int b;
        int c;

        cout << "Введите 3 стороны треугольника через пробел - (Можно использовать только целые неотрицательные числа)" << endl;

        // Проверка чисел


        if (cin >> a >> b >> c) {

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
            throw ERROR_NOT_NUMBER;
            return 1;

        }

        // Проверка на неотрицательность

        if ((a < 0) or (b < 0) or (c < 0)) {
            throw ERROR_NEGATIVE_NUMBER;
            return 1;
        }

        // Обработка ввода
            //Проверка на существование

        if ((a > b + c) or (b > a + c) or (c > b + a)) {
            throw ERROR_NOT_EXIST;
            return 1;
        }

        // Треугольник + Стороны + Тип

        cout << "Треугольник - ";

        // Тип

        if ((a * a == b * b + c * c) or (b * b == a * a + c * c) or (c * c == b * b + a * a)) {

            cout << "прямоугольный";

        }
        else {
            if ((a * a > b * b + c * c) or (b * b > a * a + c * c) or (c * c > b * b + a * a)) {

                cout << "тупоугольный";

            }
            else {

                cout << "остроугольный";

            }

        }

        // Стороны

        if ((a == b) and (a == c) and (b == c)) {

            cout << ", равносторонний.";

        }
        else if ((a == b) or (a == c) or (b == c)) {

            cout << ", равнобедренный.";

        }

    }
    catch (const char* error) {
        cerr << endl << error << endl;
    }

    return 0;
}