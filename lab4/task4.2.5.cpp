#include <iostream>
#include <iomanip>
#include <string>

uint32_t get_uint32_t() {
	uint32_t temp;
	std::cin >> temp;
	if (std::cin.fail() || std::cin.peek() != '\n') {
		throw "WRONG ARGUMENT";
	} else {
		return temp;
	}
}

int main () {
	std::cout << "Введите сторону: ";
	uint32_t N = get_uint32_t();
	try {
		for (uint32_t i = 0; i < N*2; i += 2) {
			std::string temp(i+1, '*');
			std::cout << std::setw((2*N-i-1) / 2) << "";
			std::cout << temp << std::endl;
		}
		for (int32_t i = (N-2)*2; i >= 0; i -= 2) {
			std::string temp(i+1, '*');
			std::cout << std::setw((2*N-i-1) / 2) << "";
			std::cout << temp << std::endl;
		}
	} catch (const char* error) {
		std::cerr << error << std::endl;
	} catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "UNKNOWN ERROR" << std::endl;
	}
	return 0;
}