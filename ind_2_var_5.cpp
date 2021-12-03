#include<iostream>
using namespace std;

const char* error_invalid_x = "x must be greater than -1 and less than 1 and x must be a number";
const char* error_invalid_maxNum = "max number of elements must be greater than or equal to 1";
const char* error_absError_cant_reach = "abs error can't be reach.";
const char* error_invalid_absError = "abs error must be a number";

double e(double x, int maxNum, double absError);
double cPow(double j, int powerX);

int main()
{
    double x = 0.0;
    int maxNum = 1;
    double absError = 0.0;
    cout << "Enter x, the maximum number of terms in the sum, absolute error." << std::endl;
    try
    {
        cin >> x;
        if (std::cin.peek() != '\n' || (x < -1 or x > 1))
        {
            throw error_invalid_x;
        }
        cin >> maxNum;
        if (cin.peek() != '\n' || maxNum < 1)
        {
            throw error_invalid_maxNum;
        }
        cin >> absError;
        if (cin.peek() != '\n')
        {
            throw error_invalid_absError;
        }
        double res = e(x, maxNum, absError);
        if (res == -3)
        {
            throw error_absError_cant_reach;
        }
        cout << "result: " << res;
    }
    catch (const char* error)
    {
        cerr << std::endl << error << std::endl;
        return -1;
    }
}

double e(double x, int maxNum, double absError)
{
    double a = 1.0;
    double b = 1.0;
    double summa = 1.0;
    double term = 1.0;
    double termSign = 1.0;
    double count = 1;
    double secTerm = 0.0;
    double i = 1;
    while ((count < maxNum) and (abs(term - secTerm < absError)))
    {
        a *= x;
        b *= count + 1;
        termSign *= -x;
        term = a / b;
        summa += term;
        count += 1;

    }
    if (abs(term - secTerm) > absError)
    {
        return -3;
    }
    return summa;
}

double cPow(double j, int powerX)
{
    for (int i = 1; i < powerX; i++)
    {
        j *= j;
    }
    return j;
}