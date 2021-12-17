#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

// Инициализация и объявление констант с текстами ошибок
const char* msgAccuracyError = "Error! Accuracy didn't pass with this number of terms!\n";
const char* msgAbsError = "Error! Absolute error has to be more then 0!\n";
const char* msgMaxTermsNumError = "Error! Max number of terms has to be more then 0!\n";
const char* msgDoubleInputError = "Error! Expected double number type!\n";
const char* msgIntInputError = "Error! Expected integer number type!\n";
const char* msgFunctionBoundsError = "Error! Bounds of this function are from -1 to 1 (not encluding bounds)! Expected value in this bounds!\n";
const char* msgStepError = "Error! Step has to be more then 0!\n";
const char* msgUnexError = "Unexpected error!\n";

// Объявление функции
double arcsinTaylor(double x, double accuracy, int maxTerms);

// Инициализация класса перечисления ошибок
enum class Errors {
    AccuracyError,
    AbsError,
    MaxTermsNumError,
    DoubleInputError,
    IntInputError,
    FunctionBoundsError,
    StepError
};

int main()
{
    setlocale(LC_ALL, "ru");

    double absError = 0.0;
    int maxTermsNum = 0;
    double lowerBound = 0.0;
    double upperBound = 0.0;
    double step = 0.0;

    try {
        std::cout << "Enter: " << std::endl;
        std::cout << "\tAccuracy of calculate: ";
        std::cin >> absError;

        if (!std::cin.good()) {
            throw Errors::DoubleInputError;
        }
        if (absError <= 0) {
            throw Errors::AbsError;
        }
        std::cout << "\tMax number of terms: ";
        std::cin >> maxTermsNum;
        if (!std::cin.good()) {
            throw Errors::IntInputError;
        }
        if (maxTermsNum <= 0) {
            throw Errors::MaxTermsNumError;
        }
        std::cout << "\tBounds of interval for calculating: ";
        std::cin >> lowerBound >> upperBound;
        if (!std::cin.good()) {
            throw Errors::DoubleInputError;
        }
        if (lowerBound > upperBound) { // Установка границ в порядке возрастания
            int memory = lowerBound;
            lowerBound = upperBound;
            upperBound = memory;
        }
        std::cout << "\tStep: ";
        std::cin >> step;
        if (!std::cin.good()) {
            throw Errors::DoubleInputError;
        }
        if (step <= 0) {
            throw Errors::StepError;
        }
    }
    catch (Errors ErrorMsg) { // Обработка возможных ошибок
        switch (ErrorMsg) {
        case Errors::AbsError:
            std::cerr << msgAbsError;
            return 1;
        case Errors::MaxTermsNumError:
            std::cerr << msgMaxTermsNumError;
            return 2;
        case Errors::DoubleInputError:
            std::cerr << msgDoubleInputError;
            return 3;
        case Errors::IntInputError:
            std::cerr << msgIntInputError;
            return 4;
        case Errors::StepError:
            std::cerr << msgStepError;
            return 5;
        }
    }
    catch (...) {
        std::cerr << msgUnexError;
    }

    std::cout << std::left
        << std::setw(10) << "Аргумент"
        << std::setw(15) << "Ряд Тейлора"
        << std::setw(20) << "Встроенная функция"
        << std::setw(20) << "Разница"
        << std::endl;

    for (double currentNumber = lowerBound; currentNumber <= upperBound; currentNumber += step) {
        try {
            currentNumber = round(currentNumber / step) * step; // Предотвращение неточности числа в связи со способом его хранения в памяти
            std::cout << std::left
                << std::setw(10) << currentNumber << std::setw(15);
            std::cout
                << arcsinTaylor(currentNumber, absError, maxTermsNum) // Выделение отдельной логической строки, чтобы в случае ошибки, число, приведшее к ней, вывелось на экран
                << std::setw(20) << asin(currentNumber)
                << std::setw(20) << abs(asin(currentNumber) - arcsinTaylor(currentNumber, absError, maxTermsNum))
                << std::endl;
        }
        catch (Errors ErrorMsg) { // Обработка возможных ошибок
            switch (ErrorMsg) {
            case Errors::AccuracyError:
                std::cerr << msgAccuracyError;
                break;
            case Errors::FunctionBoundsError:
                std::cerr << msgFunctionBoundsError;
                break;
            }
        }
        catch (...) {
            std::cerr << msgUnexError;
        }
    }

    return 0;
}

double arcsinTaylor(double x, double absError, int numberMax) {
    if (x <= -1 || x >= 1) {
        throw Errors::FunctionBoundsError;
    }
    double total = x;
    double currentTerm = x;
    for (double i = 1.0; i < numberMax; i++) {
        currentTerm *= (x * x * (2 * i - 1) * (2 * i - 1)) / ((2 * i) * (2 * i + 1));
        if (abs(currentTerm) < absError) {
            return total;
        }
        total += currentTerm;
    }
    if (abs(currentTerm) > absError) {
        throw Errors::AccuracyError;
    }

    return total;
}
