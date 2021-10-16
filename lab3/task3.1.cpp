#include <iostream>
#include <cmath>

const char* ZERO_DISCRIMINANT = "Дискриминант меньше нуля.";
const char* ZERO_ARGUMENT_A = "Коэффициент A не может быть нулевым";
const char* WRONG_ARGUMENT = "Коэффициент должен быть целочисленным.";

double get_sqrt_discriminant(int a, int b, int c) {
    int temp = b*b - 4*a*c;
    if (temp < 0) {
        throw ZERO_DISCRIMINANT;
    } else {
        return std::sqrt(temp);
    }
}

int get_int() {
    int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        throw WRONG_ARGUMENT;
    }
    return temp;
}

void print_roots(int a, int b, double sqrt_discriminant) {
    if (sqrt_discriminant == 0) {
        std::cout << "Единственный корень: " << -b/(2*a) << "\n";
    } else {
        std::cout << "Первый корень: " << (-b+sqrt_discriminant)/(2*a) << "\n";
        std::cout << "Второй корень: " << (-b-sqrt_discriminant)/(2*a) << "\n";
    }
}

int main() {
	setlocale(LC_CTYPE, "");
	try {
		std::cout << "Введите первый коэффициент: ";
		int a = get_int();
		if (a == 0) {
			std::cout << "";
			throw ZERO_ARGUMENT_A;
		}
		std::cout << "Введите второй коэффициент: ";
		int b = get_int();
		std::cout << "Введите третий коэффициент: ";
		int c = get_int();
		double sqrt_discriminant = get_sqrt_discriminant(a, b, c);
		print_roots(a, b, sqrt_discriminant);
	} catch (const char* error) {
		std::cerr << error << std::endl;
		return -1;
	}
	return 0;
}