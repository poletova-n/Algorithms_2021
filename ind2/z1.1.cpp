#include <iostream>

const char* ERROR_INVALID_X_INPUT = "Error: x must be only number greater than -1 and less than 1";

const char* ERROR_INVALID_TERM_MAX_NUMB_INPUT = "Error: max number of terms must be only positive integer";

const char* ERROR_INVALID_ABS_ERROR_INPUT = "Error: absolute error must be only number";

const char* ERROR_CANT_REACH_ABS_ERROR = "Error: absolute error can't be reached";

double calcFact(double in);

double calcPow(double in, int power);

double calcCos(double x, int termMaxNumb, double absError);

int main()
{
    double x = 0.0;
    int termMaxNumb = 1;
    double absError = 1.0;
    std::cout << "Enter x, max number of terms and absolute error:";
    try
    {
        std::cin >> x;
        if(x > 1.0 && x < -1.0 || (std::cin.peek() != 10 && std::cin.peek() != 32))
        {
            throw ERROR_INVALID_X_INPUT;
        }
        std::cin >> termMaxNumb;
        if(std::cin.fail() || (std::cin.peek() != 10 && std::cin.peek() != 32) || termMaxNumb < 1)
        {
            throw ERROR_INVALID_TERM_MAX_NUMB_INPUT;
        }
        std::cin >> absError;
        if(std::cin.fail() || std::cin.peek() != 10)
        {
            throw ERROR_INVALID_ABS_ERROR_INPUT;
        }
        double result = calcCos(x,termMaxNumb, absError);
        if(result == -3)
        {
            throw ERROR_CANT_REACH_ABS_ERROR;
        }
        std::cout << "Result: " << result;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

double calcCos(double x, int termMaxNumb, double absError)
{
    double termSign = -1.0;
    int i = 1;
    double term = 0.0;
    double sum = 1.0;
    do
    {
        term = calcPow(x, i*2)/ calcFact(i*2) * termSign;
        sum+=term;
        i++;
        termSign *= -1.0;
    }
    while (i <= termMaxNumb and abs(term) > absError);
    if(abs(term) > absError)
    {
        return -3;
    }
    return sum;
}

double calcPow(double in, int power)
{
    for (int i = 1; i < power; i++)
    {
        in *= in;
    }
    return in;
}

double calcFact(double in)
{
    double res = 1;
    for (int i = 2; i < in + 1; i++)
    {
        res *= i;
    }
    return res;
}