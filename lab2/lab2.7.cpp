#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);

    // Ввод значения

    int arr[3] = { 0 , 0, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);


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
    
    sort(arr, arr + n);
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}