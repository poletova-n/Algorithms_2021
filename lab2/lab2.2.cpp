#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);
    
    // Ввод значения

    int hunter[2] = { 0 , 0 }; int victim[2] = { 0 , 0 };


    cout << "Введите 4 числа - координаты 2 фигур: Сначала координаты вашей фигуры, затем координаты фигуры противника. Сначала указывается координата по вертикали, затем по горизонтали (Можно использовать только целые неотрицательные числа от 1 до 8 )" << endl;

    // Проверка чисел

    if (cin >> hunter[0] >> hunter[1] >> victim[0] >> victim[1]) {

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

    if ((8 < hunter[0]) or (hunter[0] < 1) or (8 < hunter[1]) or ( hunter[1] < 1) or  (8 < victim[0]) or (victim[0] < 1) or (8 < victim[1]) or (victim[1] < 1)) {
        cout << "Вы вышли за границы поля";
        return 1;
    }

    //cout << hunter[0] << " h1 " << hunter[1] << " h2 " << victim[0] << " v1 " << victim[1] << endl;

    // Проверка 

    if ((hunter[0] == victim[0]) or (hunter[1] == victim[1])) {
        cout << "Ладья съедает фигуру противника";
    }
    else {
        cout << "Ладья не может съесть фигуру противника";
    }
    
    return 0;
}