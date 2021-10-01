#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Ввод значения

    int hunter[2] = { 0 , 0 }; 


    cout << "Введите 2 числа - координаты фигуры: Сначала указывается координата по вертикали, затем по горизонтали (Можно использовать только целые неотрицательные числа от 1 до 8 )" << endl;

    // Проверка чисел

    if (cin >> hunter[0] >> hunter[1]) {

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

    // Проверка на поле

    if ((8 < hunter[0]) or (hunter[0] < 1)) {
        cout << "Вы вышли за границы поля";
        return 1;
    }


    // Проверка 
    cout << "Все возможные ходы: ";

    for (int i = 1; i <= 8; i++){
        if (i != hunter[1]) {
            cout << hunter[0] << ":" << i << " ";
        }
    }

    for (int i = 1; i <= 8; i++) {
        if (i != hunter[0]) {
            cout << i << ":" << hunter[1] << " ";
        }
    }

    return 0;
}