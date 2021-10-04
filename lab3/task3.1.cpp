#include <iostream>
#include <cmath>

double get_sqrt_discriminant(int a, int b, int c) {
    int temp = b*b - 4*a*c;
    if (temp < 0) {
        throw L"Дискриминант меньше нуля.";
    } else {
        return std::sqrt(temp);
    }
}

int get_int() {
    int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        throw L"Коэффициент должен быть положительным и целочисленным.";
    }
    return temp;
}

void print_roots(int a, int b, double sqrt_discriminant) {
    if (sqrt_discriminant == 0) {
        std::cout << "Единственный корень: " << -b/(2*a) << "\n";
    } else {
        std::cout << "Первый корень: " << (-b+sqrt_discriminant)/(2*a) << "\n";
        std::cout << "Первый корень: " << (-b-sqrt_discriminant)/(2*a) << "\n";
    }
}

int main() {
	setlocale(LC_CTYPE, "");
	try {
		std::cout << "Введите первый коэффициент: ";
		int a = get_int();
		if (a == 0) {
			std::cout << "";
			throw L"Коэфициент A не может быть нулевым";
		}
		std::cout << "Введите второй коэффициент: ";
		int b = get_int();
		std::cout << "Введите третий коэффициент: ";
		int c = get_int();
		double sqrt_discriminant = get_sqrt_discriminant(a, b, c);
		print_roots(a, b, sqrt_discriminant);
	} catch (const wchar_t* error) {
		std::wcerr << error << std::endl;
		return -1;
	}
	return 0;
}