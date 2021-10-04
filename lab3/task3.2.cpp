#include <iostream>

const char* NOT_INT_ARGUMENT = "Коэффициент должен быть целочисленным.";
const char* NEGATIVE_ARGUMENT = "Количество ворон должно быть положительным.";

int get_int() {
    int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        throw NOT_INT_ARGUMENT;
    }
    return temp;
}

int main() {
	setlocale(LC_CTYPE, "");
	try {
		std::cout << "Введите количество ворон: ";
		int ravensCount = 0;
		ravensCount = get_int();
		if (ravensCount < 0) {
			throw NEGATIVE_ARGUMENT;
		}
		int ravensCount100 = ravensCount % 100;
		if (((ravensCount100 >= 10) && (ravensCount100 % 100 < 20)) || (ravensCount100 == 0)) {
			std::cout << "В стае " << ravensCount << " ворон." << std::endl;
		} else {
			int ravensCount10 = ravensCount % 10;
			if (ravensCount10 == 1) {
				std::cout << "В стае " << ravensCount << " ворона." << std::endl;
			} else if (ravensCount10 == 5) {
				std::cout << "В стае " << ravensCount << " ворон." << std::endl;
			} else {
				std::cout << "В стае " << ravensCount << " вороны." << std::endl;
			}
		}
	}
	catch (const char* error) {
		std::cerr << error << std::endl;
		return -1;
	}
	return 0;
}
