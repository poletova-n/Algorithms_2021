//Вводим библиотеки
#include <iostream>
#include <windows.h>
#include <cmath>

//Вводим исключения
const char* ERROR_INCORRECT_X = "Ошибка: вы вышли за пределы диапазона или ввели не число!";
const char* ERROR_POSITIVE_TERM_MAX_NUMBER = "Ошибка: максимальное число последовательности должно быть положительным";
const char* ERROR_NOT_NUMBER_ABS_ERROR = "Ошибка: абсолютная погрешность должно быть числом";

//Объявляем функции
double compLn(double x, int numberMax, double absError);
double compPow(double n, int power);
double compDen(double n);
double compNum(double n);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //Объявляем переменные
    double x1 = 0.0, x2 = 0.0;
    int numberMax = 4;
    double shag;
    double absError = 10E-5;
    //Проверяем исключения
    try
    {
        std::cout << "Введите интервал от x1 и x2: ";
        std::cin >> x1 >> x2;
        if(((x1 >= 1.0 || x1 <= -1.0) || (x2 >= 1.0 || x2 <= -1.0)) || (std::cin.peek() != 10 && std::cin.peek() != 32))//Если х меньше -0.9 или больше 0.9 или введенное значение не число, вывод исключения
        {
            throw ERROR_INCORRECT_X;
        }
        std::cout << std::endl;
        std::cout << "Введите шаг интервала: ";
        std::cin >> shag;
        if(shag < 0 || (shag > abs(x2) || shag > abs(x1)) || (std::cin.peek() != 10 && std::cin.peek() != 32))//Если х меньше -0.9 или больше 0.9 или введенное значение не число, вывод исключения
        {
            throw ERROR_INCORRECT_X;
        }
        std::cout << std::endl;
        std::cout << "Введите число последовательности: ";
        std::cin >> numberMax;
        if((std::cin.peek() != 10 && std::cin.peek() != 32) || numberMax < 1)//Если numberMax не число или отрицательное число, вывод исключения
        {
            throw ERROR_POSITIVE_TERM_MAX_NUMBER;
        }
        std::cout << std::endl;
        std::cout << "Введите абсолютную погрешность: ";
        std::cin >> absError;
        if (std::cin.fail() || std::cin.peek() != 10)//Если absError не число, вывод исключения
        {
            throw ERROR_NOT_NUMBER_ABS_ERROR;
        }
        std::cout << std::endl;
        std::cout << "-----------------------------------\n";
        std::cout << "x\tРезультат\n";//Выводим результат
        std::cout << "-----------------------------------\n";
        for (double i = x1; i <= x2; i += abs(shag))
        {
            double result = compLn(i,numberMax,absError);
            if(result < 0 && result > -1.38778e-16)
            {
                std::cout << "0   " << "        " << result << std::endl;
            }
            else
            {
                if(result == -3)//Если абсолютная погрешность не достигаема, вывод исключения
                {
                    std::cout << "Точность не достигнута!" << std::endl;
                }
                else
                {
                    std::cout << i << "        " << result << std::endl;
                }
            }
        }
        std::cout << "-----------------------------------";
    }
    catch (const char* error)//Ловим исключения
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}


double compLn(double x, int numberMax, double absError)//Функция выводит результат последовательности
{
    double termSign = -1.0;
    int i = 1;
    double term;
    do
    {
        term = (compNum(i) / compDen(i)) * ( compPow(x, ((i+2)+(i-1)) ) / ( (i+2)+(i-1)) ) * termSign;//Подсчет каждого слагаемого
        term = round(term*(1/absError))/(1/absError);
        i++;
        termSign *= -1.0;
        x += term;
    }
    while(i <= numberMax && absError <= abs(term));
    if (absError <= abs(term))//Функция вернет -3, если абсолютная погрешность станет меньше модуля числа слагаемого
    {
        return -3;
    }
    return x;
}

double compPow(double n, int power)//Функция для степени
{
    for (int i = 1; i < power; i++)
    {
        n *= n;
    }
    return n;
}

double compNum(double n)//Функция для числителя
{
    double num = 1.0;
    for (int i = 1; i < n+2; i+=2)
    {
        num *= i;//Умножение каждого множителя в числителе
    }
    return num;//Возврат произведения числителя
}

double compDen(double n)//Функция для знаменателя
{
    double den = 1.0;
    for (int i = 2; i < n+3; i+=2)
    {
        den *= i;//Умножение каждого множителя в знаменателе
    }
    return den;//Возврат произведения знаменателя
}

