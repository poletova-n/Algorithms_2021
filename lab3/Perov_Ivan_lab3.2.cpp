#include <iostream>
#include <cmath>
using namespace std;
const char* ERROR_NOT_INTEGER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NOT_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_A0 = "Если a = 0, значит это не квадратное уравнение";

int main() {
    try {
        setlocale(LC_ALL, "Russian");  //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

        double a;
        double b;
        double c;
        double dsk;
        double x1;
        double x2;
        int x1check;
        int x2check;

        cout << "Введите 3 числа через пробел в порядке a b c - (Можно использовать только целые числа)" << endl;
        if (cin >> a >> b >> c) {

            if (cin.peek() == EOF || cin.peek() == '\n')
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

        if (a == 0) {
            throw ERROR_A0;
            return 1;
        }
        dsk = sqrt((b * b) - (4 * a * c));

        x1 = (-b + dsk) / (2 * a);
        x2 = (-b - dsk) / (2 * a);

        x1check = (-b + dsk) / (2 * a);
        x2check = (-b - dsk) / (2 * a);

        if ((x1check == x1) and (x2check == x2)) {
            cout << "Корни: " << endl << x1 << endl << x2;
        }
        else if (x1check == x1) {
            cout << "Целочисленный корень - " << x1 << endl;
        }

        else if (x2check == x2) {
            cout << "Целочисленный корень  - " << x2;
        }
        else {
            cout << "Целочисленных корней не существует";
        }
    }
    catch (const char* error) {
        cerr << endl << error << endl;
    }
    return 0;
}