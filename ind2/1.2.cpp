#include<iostream>

const char* error_invalid_x = "x must be greater than -1 and less than 1 and x must be a number. End of the program";
const char* error_invalid_maxNum = "The maximum number of elements must be greater than or equal to 1.";
const char* error_absError_cant_reach = "Absolute error can't be reach.";
const char* error_invalid_absError = "Absolute error must be a number.";

double arcTg(double x, int maxNum, double absError);
double cPow(double j, int powerX);

int main()
{
    double x = 0.0;
    int maxNum = 1;
    double absError = 0.0;
    std::cout << "Enter x, the maximum number of terms in the sum, absolute error."<< std::endl;
    try
    {
        std::cin >> x;
        if (std::cin.peek() != '\n' || (x < -1 or x > 1))
        {
            throw error_invalid_x;
        }
        std::cin >> maxNum;
        if (std::cin.peek() != '\n' || maxNum < 1)
        {
            throw error_invalid_maxNum;
        }
        std::cin >> absError;
        if(std::cin.peek() != '\n')
        {
            throw error_invalid_absError;
        }
        double res = arcTg(x, maxNum, absError);
        if (res == -3)
        {
            throw error_absError_cant_reach;
        }
        std::cout << "result: " << res;
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

double arcTg(double x, int maxNum, double absError)
{
    double summa = x;
    double term = 1.0;
    double termSign = -1.0;
    double count = 0;
    double i = 3;
    while ((count < maxNum) and (abs(summa) < absError))
    {
        term = (cPow(x,i)/i) * termSign;
        summa += term;
        count ++;
        i += 2;
        termSign *= -1.0;
    }
    if (abs(summa) > absError)
    {
        return - 3;
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
