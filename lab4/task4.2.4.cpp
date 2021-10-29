#include <iostream>
#include <string>

uint32_t get_uint32_t() {
    int temp;
    std::cin >> temp;
    if (std::cin.fail() || std::cin.peek() != '\n') {
        throw "WRONG ARGUMENT";
    } else if (temp < 0) {
        throw "NEGATIVE ARGUMENT";
    } else {
        return static_cast<uint32_t>(temp);
    }
}

int main () {
	std::cout << "Введите сторону: ";
	try {
        uint32_t N = get_uint32_t();
		for (uint32_t i = 0; i < N; i++) {
			std::string temp(i+1, '*');
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