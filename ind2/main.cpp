#include<iostream>
#include <iomanip>
void sinhFunc(double absError, double x, int NumberMax, double& result);
void output(int precision, double x, double result);
void inputError(int check);
int factorial(int value);
int main() {
    int precision = 0, numberMax = 0, precPrep = 0;
    double leftBorder = 0, rightBorder = 0, step = 0;
    double absErr = 0, sresult = 0;
    std::cout << "Input absErr \n";
    while (!(std::cin >> absErr) || (absErr < 0)){
        absErr = 0;
        inputError(1);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    }
    std::cout << "Input the number of sequence terms \n";
    while (!(std::cin >> numberMax) || (numberMax < 0)) {
        numberMax = 0;
        inputError(2);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    }
    std::cout << "Input borders \n";
    while (!(std::cin >> leftBorder) || !(std::cin >> rightBorder) || leftBorder <= -1 || rightBorder >= 1 || leftBorder > rightBorder) {
        leftBorder = 0;
        rightBorder = 0;
        inputError(3);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    }
    std::cout << "Input step\n";
    while (!(std::cin >> step) || (step < 0)) {
        step = 0;
        inputError(4);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    }
    std::cout << std::setw(25) << "X";
    std::cout << std::setw(25) << "formula value";
    std::cout << std::setw(25) << "func value";
    std::cout << std::setw(30) << "precision\n";
    if (absErr <= 1) {
        precPrep = (1 / absErr);
        while ((precPrep > 1) && (precPrep != 0)) {
            precision++;
            precPrep /= 10;
        }
    }
    for (double x = leftBorder; x <= rightBorder; x += step) {
        try {
            x = round(x * 100000) / 100000;
            sinhFunc(absErr, x, numberMax, sresult);
            output(precision, x, sresult);
            std::cout << std::setw(35) << "precision achieved\n";
        }
        catch (int) {
            output(precision, x, sresult);
            std::cout << std::setw(35) << "precision unachieved\n";
        }
    }
}
void sinhFunc(double absError, double x, int numberMax, double& result) {
    double term = x;
    double res = term;
    for (int i = 3; i <= numberMax; i+=2) {
        term *= x * x / factorial(i);
        if (abs(term) <= absError) {
            result = res;
            return;
        }
        result = res;
        res += term;
    }
    throw - 1;
}
void output(int precision, double x, double result)
{
    std::cout << std::setw(25) << x;
    std::cout << std::setw(25) << std::setprecision(precision + 1.0) << result;
    if (precision == 0) {
        std::cout << std::setw(25) << std::setprecision(6) << sinh(x);
    }
    else {
        std::cout << std::setw(25) << std::setprecision(precision + 1.0) << sinh(x);
    }
}
void inputError(int check)
{
    std::cerr << "Input error. ";
    if (check == 1) {
        std::cerr << "Input asbErr again \n";
    }
    else if (check == 2) {
        std::cerr << "Input X again \n";
    }
    else if (check == 3) {
        std::cerr << "Input borders again \n";
    }
    else if (check == 4) {
        std::cerr << "Input step again \n";
    }
    std::cin.clear();
}
int factorial(int value)
{
    for (int l=value-1;l>0;--l)
    {
        value*=l;
    }
    return value;
}
