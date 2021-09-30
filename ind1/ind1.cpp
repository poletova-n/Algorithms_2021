#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int a(0), b(0), count(1), countMax(0);
    cin >> a;
    if (cin.fail() or cin.peek() != 10) {
        cout << "Ошибка! Вводите только целые числа.";
        return 0;
    }
    b = a;
    if (a != 0) {
        while (true) {
            cin >> a;
            if (cin.fail() or cin.peek() != 10) {
                cout << "Ошибка! Вводите только целые числа.";
                return 0;
            }
            if (a == 0) {
                break;
            }
            if (a < b) {
                count += 1;
                if (count > countMax) {
                    countMax = count;
                }
            }
            else {
                count = 1;
            }
            b = a;
        }
    }
    cout << "Наибольшая длина монотонно убывающего фрагмента последовательности: " << countMax;
}