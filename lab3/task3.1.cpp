#include <iostream>
#include <string>

template <typename T> T get_value() {
	T temp = 0;
	std::cin >> temp;
	if (std::cin.fail() or std::cin.peek() != '\n') {
		std::cout << "Коэффициент должен быть положительным и целочисленным.\n";
		std::exit(1);
	}
	return temp;
}

int main () {
	int side = get_value<int>();
	side = side*2 - 1;
	std::string asterisk = "*";
	std::string space = " ";
	for (int32_t i = 1; i <= side; i+=2) {
		//std::cout << i;
		for (int32_t j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	for (uint32_t i = side-2; i > 1; i-=2) {
		for (uint32_t j = 0; j < side/2 - i; j++) {
			std::cout << " ";
		}
		for (uint32_t j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << "*";
}