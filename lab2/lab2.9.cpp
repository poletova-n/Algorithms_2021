#include <iostream>
using namespace std;


int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Ввод значения

    int arr[3] = { 0 , 0, 0 };
    int ch = 0;
    int nch = 0;


    cout << "Введите 3 числа (Можно использовать только целые числа )" << endl;

    // Проверка чисел

    if (cin >> arr[0] >> arr[1] >> arr[2]) {

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

    for (int i = 0; i < 3; i++) {
        if (arr[i] % 2 == 0) {
            ch = ch + 1;
        }
        else {
            nch = nch + 1;
        }
    }
    if (nch > 0 and ch > 0) {
        cout << "Да";
    }
    else {
        cout << "Нет";
    }
    return 0;
}