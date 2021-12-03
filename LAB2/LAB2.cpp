#include <iostream>

const char* ERROR_INVALID_FIRST_BORDER_INPUT = "Error: first border must be only number greater than -1 and less than 1";

const char* ERROR_INVALID_SECOND_BORDER_INPUT = "Error: second border must be only number greater than -1 and less than 1 and less than greater than first boarder";

const char* ERROR_INVALID_TERM_MAX_NUMB_INPUT = "Error: max number of terms must be only positive integer";

const char* ERROR_INVALID_STEP_INPUT = "Error: step must be only number";

const char* ERROR_INVALID_ABS_ERROR_INPUT = "Error: absolute error must be only number";

const char* ERROR_CANT_REACH_ABS_ERROR = "Error: absolute error can't be reached";

double calcFact(double in);

double calcPow(double in, int power);

double calcCosH(double x, int termMaxNumb, double absError);

double myRound(double in, double absError);

int main()
{
    double finish = 0.0;
    int termMaxNumb = 1;
    double absError = 1.0;
    double start = 0.0;
    double step = 0.0;
    std::cout << "Enter right boundary of the interval, left boundary of the interval, step, max number of terms and absolute error:";
    try
    {
        std::cin >> start;

        if (std::cin.fail() || start > 1.0 || start < -1.0 || (std::cin.peek() != 10 && std::cin.peek() != 32))
        {
            throw ERROR_INVALID_FIRST_BORDER_INPUT;
        }

        std::cin >> finish;

        if (std::cin.fail() || finish > 1.0 || finish < -1.0 || (std::cin.peek() != 10 && std::cin.peek() != 32) || finish < start)
        {
            throw ERROR_INVALID_SECOND_BORDER_INPUT;
        }

        std::cin >> step;

        if (std::cin.fail() || (std::cin.peek() != 10 && std::cin.peek() != 32) || step > 1)
        {
            throw ERROR_INVALID_STEP_INPUT;
        }

        std::cin >> termMaxNumb;

        if (std::cin.fail() || (std::cin.peek() != 10 && std::cin.peek() != 32) || termMaxNumb < 1)
        {
            throw ERROR_INVALID_TERM_MAX_NUMB_INPUT;
        }

        std::cin >> absError;

        if (std::cin.fail() || std::cin.peek() != 10)
        {
            throw ERROR_INVALID_ABS_ERROR_INPUT;
        }

        for (double i = start; i < finish; i += step) {

            double result = calcCosH(i, termMaxNumb, absError);

            if (result == -3)
            {
                throw ERROR_CANT_REACH_ABS_ERROR;
            }
            std::cout << "x = " << " " << myRound(i, step) << "\t," << "result: " << myRound(result, absError) << std::endl;
        }
    }
    catch (const char* error)
    {
        system("cls");

        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

double calcCosH(double x, int termMaxNumb, double absError)
{
    int i = 1;
    double term = 0.0;
    double sum = 1.0;
    double lastTerm = 0.0;

    do
    {
        term = calcPow(x, i * 2) / calcFact(i * 2);
        sum += term;
        i++;
        lastTerm = term;
    } while (i <= termMaxNumb and abs(term - lastTerm) < absError);

    if (termMaxNumb == i)
    {
        return -3;
    }
    return sum;
}

double calcPow(double in, int power)
{
    double res = in;

    for (int i = 1; i < power; i++)
    {
        res *= in;
    }

    return res;
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

double myRound(double in, double absError)
{
    return floor(in * (1 / absError)) / (1 / absError);
}