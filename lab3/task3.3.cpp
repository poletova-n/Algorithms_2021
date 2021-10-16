#include <iostream>

const char* WRONG_ARGUMENT = "Сторона должна быть положительной и целочисленной.";
const char* TRIANGLE_IS_NOT_EXIST = "Треугольник не существует.";

int get_value() {
	int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() || std::cin.peek() != '\n' || temp <= 0) {
        throw WRONG_ARGUMENT;
    }
    return temp;
}

uint32_t get_max(uint32_t a, uint32_t b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

uint32_t get_min(uint32_t a, uint32_t b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main () {
	setlocale(LC_CTYPE, "");
	try {
		int a, b, c;
		std::cout << "Введите первую сторону: ";
		a = get_value();
		std::cout << "Введите вторую сторону: ";
		b = get_value();
		std::cout << "Введите третью сторону: ";
		c = get_value();
		uint32_t sum = a + b + c;
		uint32_t max = get_max(get_max(a, b), c);
		uint32_t min = get_min(get_min(a, b), c);
		uint32_t middle = sum - min - max;

		if (middle + min <= max) {
			throw TRIANGLE_IS_NOT_EXIST;
		}
		if ((a == b) && (a == c) && (b == c)) {
			std::cout << "Треугольник равносторонний." << std::endl;
		} else if ((a == b) || (a == c) || (b == c)) {
			std::cout << "Треугольник равнобедренный." << std::endl;
		} else {
			std::cout << "Треугольник общего вида." << std::endl;
		}
		if (middle * middle + min * min == max * max) {
			std::cout << "Треугольник прямоугольный." << std::endl;
		} else if (middle * middle + min * min < max * max) {
			std::cout << "Треугольник тупоугольный." << std::endl;
		} else {
			std::cout << "Треугольник остроугольный." << std::endl;
		}
	}
	catch (const char* error) {
		std::cerr << error << std::endl;
	}
	return 0;
}
