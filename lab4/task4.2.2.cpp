#include <iostream>
#include <vector>

std::vector<std::vector<int32_t>> fields(int row, int column) {
	std::vector<std::vector<int32_t>> result;
	for (int32_t i = 0; i < 8; i++) {
		for (int32_t j = 0; j < 8; j++) {
			if (abs(i-row) == abs(j-column)) {
				result.push_back({i+1,j+1});
			}
		}
	}
	return result;
}

int get_int() {
	int temp;
	std::cin >> temp;
	if (std::cin.fail() || std::cin.peek() != '\n') {
		throw "WRONG ARGUMENT";
	} else {
		return temp;
	}
}

int main () {
    try {
        std::cout << "Введите первую координату: ";
        int row = get_int();
        if (row < 0 || row > 8) {
            throw "ROW MUST BE IN RANGE FROM 1 TO 8";
        }
        std::cout << "Введите вторую координату: ";
        int column = get_int();
        if (column < 0 || column > 8) {
            throw "ROW MUST BE IN RANGE FROM 1 TO 8";
        }
		auto dots = fields(row-1, column-1);
		for (auto &dot: dots) {
			std::cout << dot[0] << " " << dot[1] << std::endl;
		}
	} catch (const char* error) {
		std::cerr << error << std::endl;
	} catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "UNKNOWN ERROR" << std::endl;
	}
}