#include <iostream>
#include <cmath>
using namespace std;
const char* ERROR_NOT_INTEGER = "Можно использовать только целые неотрицательные числа - Вы ввели нецелые числа";
const char* ERROR_NOT_NUMBER = "Можно использовать только целые неотрицательные числа - Вы ввели символы";
const char* ERROR_SL0 = "Число слагаемых не может быть меньше 1";
const char* ERROR_ABS0 = "Погрешность не может быть меньше 0";
const char* ERROR_OTS = "Ваш x не попадает в интервал от -1 до 1";

long double fact(int iter)
{
    if (iter < 0) {
        return 0;
    }
    if (iter == 0) {
        return 1;
    }
    else {
        return iter * fact(iter - 1);
    }
}

long double power(double x, int iter) {
    int st = iter - 1;
    double z = x;
    while (st > 0) {
        x = x * z;
        st--;
    }
    return x;
}



int main() {
    setlocale(0, "");

    double x; // отсчет
    int numberMax; // число слагаемых
    double absError; // погрешность
    double step; //шаг
    int steptemp; // номер текущего слагаемого
    long double sum2 = 0;
    long double itg;
    try {
        
        // Ввод x
        cout << "Введите x (Доступен интервал от - 1 до 1)" << endl;
        if (cin >> x) {

        }
        else
        {
            cin.ignore(100, '\n');
            cin.clear();
            throw  ERROR_NOT_NUMBER;
            return 1;

        }

        if (x < -1 or x > 1) {
            throw ERROR_OTS;
            return 1;
        }

        // Ввод кол-ва слагаемых
        cout << "Введите количество слагаемых" << endl;
        if (cin >> numberMax) {

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
        if (numberMax < 1) {
            throw ERROR_SL0;
            return 1;
        }

        // Ввод допустимой погрешности
        cout << "Введите погрешность" << endl;;
        if (cin >> absError) {


        }
        else
        {
            cin.ignore(100, '\n');
            cin.clear();
            throw  ERROR_NOT_NUMBER;
            return 1;

        }
        if (absError < 0) {
            throw ERROR_ABS0;
            return 0;
        }

        //Ввод шага
        cout << "Введите шаг" << endl;
        if (cin >> step) {


        }
        else
        {
            cin.ignore(100, '\n');
            cin.clear();
            throw  ERROR_NOT_NUMBER;
            return 1;

        }
        cout << "x = " << x << " " << "Кол-во слагаемых = " << numberMax << " " << "Погрешность = " << absError << " " << "Шаг = " << step << endl << endl;

        for (double xtemp = x; xtemp>= -1 and xtemp <= 1; xtemp = xtemp + step ){

            long double sum1 = xtemp;
            steptemp = numberMax -1 ;

            while (steptemp > -1) {
                if (steptemp % 2 == 0) {
                    sum1 = sum1 + ((power(x, 3 + 2 * steptemp) / fact(3 + 2 * steptemp)) * (-1));
                    steptemp--;

                }
                else {
                    sum1 = sum1 + (power(x, 3 + 2 * steptemp) / fact(3 + 2 * steptemp)); 
                    steptemp--;
                }
            }
            if (numberMax % 2 == 0) {
                sum2 = sum1 + ((power(x, 3 + 2 * numberMax) / fact(3 + 2 * numberMax)) * (-1));

            }
            else {
                sum2 = sum1 + (power(x, 3 + 2 * numberMax) / fact(3 + 2 * numberMax));
            }

        
            itg = sum2 - sum1;
            if(itg < 0){
                itg = itg * -1;
            }


            cout << xtemp << "               " << sum1 << "                " << sum2 << "                 " ;

                   


            if (itg > absError) {
                cout << "Точнность не достигнута" << endl;

            }
            else {

                cout << "Точность достигнута" << endl;
            }
        
        }

    }
    catch (const char* error) {
        cerr << endl << error << endl;
    }
    return 0;
}



