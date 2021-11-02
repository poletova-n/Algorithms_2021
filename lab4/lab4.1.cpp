#include <iostream>
#include <windows.h>
using namespace std;

const char* ERROR_INVALID_VALUE = "Ошибка! Введенные числа должны быть целыми.";

int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        double x(0), sum(0), sumPositive(0), n(1), nPositive(1), myMin(9999), myMinNum(0), myMax(-9999), myMaxNum(0);
        cout << "Введите последовательность чисел: \n";
        cin >> x;
        if (cin.fail() or cin.peek() != 10) {
            throw ERROR_INVALID_VALUE;
        }
        else if (x == 0) {
            cout << "Задана пустая последовательность.";
            return 0;
        }
        else {
            while (x != 0) {
                    n += 1;
                    sum += x;
                    if (x > 0) {
                        sumPositive += x;
                        nPositive += 1;
                        if (x < myMin) {
                            myMin = x;
                            myMinNum = n;
                        }
                    }
                    if (x > myMax) {
                        myMax = x;
                        myMaxNum = n;
                    }
                cin >> x;
                if (cin.fail() || cin.peek() != 10) {
                    throw ERROR_INVALID_VALUE;
                }
                }

            }
        if (myMin == 9999) {
            cout << "Сумма всех чисел = " << sum << "\n" << "Среднее арифметическое всех чисел = " << sum / (n - 1) << "\n"
                 << "Среднее арифметическое положительных чисел = " << "0" << "\n"
                 << "Максимальное значение = " << myMax << " Его номер: " << (myMaxNum - 1) << "\n"
                 << "Минимальное положительное значение = " << "-" << " Его номер: " << "-";
            return 0;
        }
        cout << "Сумма всех чисел = " << sum << "\n" << "Среднее арифметическое всех чисел = " << sum / (n - 1) << "\n"
                 << "Среднее арифметическое положительных чисел = " << sumPositive / (nPositive - 1) << "\n"
                 << "Максимальное значение = " << myMax << " Его номер: " << (myMaxNum - 1) << "\n"
                 << "Минимальное положительное значение = " << myMin << " Его номер: " << (myMinNum - 1);
        }
    catch(const char* error) {
        cerr << endl << error << endl;
        return -1;
    }
}
