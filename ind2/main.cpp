#include <iostream>
#include <exception>
#include <iomanip>

namespace laba2
{

    double F(double x, int maxNum, double absError);

}



double laba2::F(double x, int maxNum, double absError) {

    double sum = 0, k = 0, pred = 1.0, tek = 1.0;

    for (double i = 1; i <= maxNum; i++) {

        if (k > 0) tek = pred * x * x / (k * (k - 1));

        pred = tek;

        if (std::abs(tek) < absError) break;

        sum = sum + tek;

        k = k + 2;

    }

    if (std::abs(pred) > absError) throw std::logic_error("Accuracy has not been achieved");

    return (sum);

}




void examFail() {

    if (std::cin.fail())

        throw std::logic_error("Error");

}

int main() {

    double absError = 0, x0 = 0, x1 = 0, step = 0, x = 0;

    int maxNum = 0;

    try {

        std::cout << "Enter the precision: "; std::cin >> absError; examFail();

        if (absError < 0) throw std::logic_error("Error");

        std::cout << "Enter maximum number of terms: "; std::cin >> maxNum; examFail();

        if (maxNum < 0) throw std::logic_error("Error");

        std::cout << "Enter the beginning of the interval: "; std::cin >> x0; examFail();

        std::cout << "Enter the end of the interval: "; std::cin >> x1; examFail();

        if (x0 > x1) throw std::logic_error("The beginning of the interval is greater than the end");

        if (x0 <= -1 || x1 >= 1) throw std::logic_error("The interval is incorrect");

        std::cout << "Enter the step of the interval: "; std::cin >> step; examFail();

        if (step < 0) throw std::logic_error("Error");

    }

    catch (const std::logic_error& error) {

        std::cerr << error.what();

        return 1;

    }

    std::cout << std::left

              << std::setw(10) << "Value"

              << std::setw(15) << "Sum"

              << std::setw(20) << "Built-in function"

              << std::setw(15) << "Did it coincide"

              << std::endl;

    for (double j = x0; j < x1; j += step) {

        try {

            double func = laba2::F(round(j / step) * step, maxNum, absError);

            double func_2 = std::cosh(round(j / step) * step);

            std::cout << std::left

                      << std::setw(10) << round(j / step) * step

                      << std::setw(15) << func

                      << std::setw(20) << func_2

                      << std::setw(15) << ((std::abs(func - func_2) < absError) ? "Yes" : "No")

                      << std::endl;

        }

        catch (const std::logic_error& error) {

            std::cerr << error.what();

            return 2;

        }

    }

    return 0;

}