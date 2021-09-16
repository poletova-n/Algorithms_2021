#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

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

            cout << endl << "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа " << endl;
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

    if ((a < 0) or (b < 0) or (c < 0)) {
        cout << "Можно использовать только целые неотрицательные числа - Вы ввели отрицательное число";
        return 1;
    }

// Обработка ввода
    //Проверка на существование

    if ((a > b + c) or (b > a + c) or (c > b + a)) {
        cout << "Такой треугольник не существует";
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

    if (a == b == c) {
        
        cout << ", равносторонний.";

    }

    if ((a == b) or (a == c) or (b == c)){

        cout << ", равнобедренный.";

    }

    return 0;
}