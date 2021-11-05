#include <iostream>

const char* WRONG_ARGUMENT = "WRONG ARGUMENT";
const char* EMPTY_SEQUENCE = "EMPTY SEQUENCE";
const char* SHORT_SEQUENCE = "SHORT SEQUENCE";

bool get_int(int &temp) {
	std::cin >> temp;
	auto next = std::cin.peek();
	if (std::cin.fail() or not (next == '\n' or next == ' ')) {
		throw WRONG_ARGUMENT;
	}
	return temp != 0;
}

int main() {
	try {
		int temp = 0;
		int previous = 0;
		get_int(previous);
		size_t count = 0;
		if (previous == 0) {
			throw EMPTY_SEQUENCE;
		}
		size_t counter = 1;
		while (get_int(temp)) {
			counter++;
			if (temp % previous == 0) {
				count++;
			}
			previous = temp;
		}
		if (counter == 1) {
			throw SHORT_SEQUENCE;
		}
		std::cout << count << " элементов этой последовательности делится на предшествующий элемент без остатка." << std::endl;
	} catch (const char* error) {
		std::cerr << error << std::endl;
	} catch(std::exception& error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "UNKNOWN ERROR" << std::endl;
	}
}