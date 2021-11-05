#include <iostream>
#include <iomanip>

const char* NOT_IN_RANGE = "X IS NOT IN RANGE [-1; 1]";
const char* PRECISION_IS_NOT_REACHED = "PRECISION IS NOT REACHED";

double dpower (double base, uint32_t n) {
	double temp = 1;
	for (uint32_t i = 0; i < n; i++) {
		temp *= base;
	}
	return temp;
}

uint32_t factorial(uint32_t n) {
	uint32_t temp = 1;
	for (uint32_t i = 2; i <= n; i++) {
		temp *= i;
	}
	return temp;
}

double exp(uint32_t maximal, double x, double precision) {
	if (x > 1 || x < -1) {
		throw NOT_IN_RANGE;
	}
	double temp = 0.0;
	double step;
	uint32_t i = 0;
	do {
		step = dpower(x, i) / factorial(i);
		temp += step;
		i++;
	} while (i < maximal && std::abs(step) > precision);
	if (i == maximal && std::abs(step) > precision) {
		throw PRECISION_IS_NOT_REACHED;
	} else {
		return temp;
	}
}

int main () {
	double precision = 0.0;
	uint32_t maximal = 0;
	double left_border = 0.0;
	double right_border = 0.0;
	double step = 0.0;
	std::cin >> precision;
	std::cin >> maximal;
	std::cin >> left_border;
	std::cin >> right_border;
	std::cin >> step;
	for (double x = left_border; x <= right_border; x += step) {
		try {
			std::cout << std::setw(12) << std::right << std::setprecision(10) << x << std::left << " | ";
			std::cout << exp(maximal, x, precision) << std::endl;
		} catch (const char* error) {
			std::cout << error << std::endl;
		}
	}
	return 0;
}