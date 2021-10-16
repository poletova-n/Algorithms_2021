#include <iostream>
#include <math.h>
#include <exception>
#include <iomanip>

const char* ERROR_INPUT_FAIL = "You went out of range or entered not a number, program termination!";
const char* ERROR_INPUT_X_LOW_HI = "The entered x is out of range, program termination!";

double funcZ(int a);
double funcH(int a);
double funci(double a, int count);
double mypow(double xF, int degree);

int main()
{
    int N = 0, j = 0, count = 0, k = 0;
    double x = 0.0, absError = 0.0, step = 0.0, result = 0.0, x1 = 0.0, x2 = 0.0, absError1 = 0.0, rounding = 1.0;
    try
    {
        std::cout << "Enter x1 and x2: ";
        std::cin >> x1 >> x2;;
        if ((std::cin.fail()) or (std::cin.peek() != 10))
        {
            throw ERROR_INPUT_FAIL;
        }
        if ((x1 > 1) or (x1 < -1) or (x2 > 1) or (x2 < -1))
        {
            throw ERROR_INPUT_X_LOW_HI;
        }
        std::cout << "Enter number of digits: ";
        std::cin >> count;
        if ((std::cin.fail()) or (std::cin.peek() != 10) or (count < 0))
        {
            throw ERROR_INPUT_FAIL;
        }
        std::cout << "Enter the absolute error: ";
        std::cin >> absError;
        if ((std::cin.fail()) or (std::cin.peek() != 10) or (absError < 0))
        {
            throw ERROR_INPUT_FAIL;
        }
        absError1 = absError;
        while (absError1 < 1)
        {
            absError1 *= 10;
            k++;
        }
        std::cout << "Enter spacing step: ";
        std::cin >> step;
        if ((std::cin.fail()) or (std::cin.peek() != 10) or (step < 0))
        {
            throw ERROR_INPUT_FAIL;
        }
        double i = x1 + step;
        for (i; i < x2; i += abs(step))
        {
            result = funci(i, count);
            if (abs(funci(i, count + 1) - funci(i, count)) < absError)
            {
                std::cout << std::fixed << std::setprecision(k) << "x = " << i << ";   my result = " << result << ";    functiion result = " << sqrt(1 + i) << std::endl;
            }
            else
            {
                std::cout << "The required accuracy has not been achieved!" << std::endl;
            }
        }


    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
    return 0;
}
double mypow(double xF, int degree)
{
    int i = 0;
    double function = 1.0;
    for (i = 1; i <= degree; i++)
    {
        function *= xF;
    }
    return function;
}

double funcH(int a)
{
    int mean = 1;
    for (int i = 1; i <= a; i++)
    {
        if (i % 2 != 0)
        {
            mean *= i;
        }
    }
    return mean;
}

double funcZ(int a)
{
    int i, mean = 1;
    if (a != 1)
    {
        for (i = 1; i < a; i++)
        {
            mean *= 2 * i;
        }
    }
    else
    {
        return 1;
    }
    return mean;
}

double funci(double a, int count)
{
    int  k = 0;
    double f = 1.0;
    for (int i = 2; i <= count; i++)
    {
        if (i % 2 == 0)
        {
            k = 1;
        }
        else
        {
            k = -1;
        }
        f = f + k * double(funcH(i) / funcZ(i)) * mypow(a, i - 1);
    }
    return f;
}