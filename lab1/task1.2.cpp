#include <iostream>

int get_int() {
    int temp = 0;
    std::cin >> temp;
    if (std::cin.fail() or std::cin.peek() != '\n') {
        std::cout << "Коэфициент должен быть целочисленным.\n";
        std::exit(1);
    }
    return temp;
}

int main() {
    std::cout << "Введите количество ворон." << std::endl;
    int ravensCount = 0;
    ravensCount = get_int();
	if (ravensCount < 0) {
		std::cout << "Количество ворон не можеть быть меньше нуля." << std::endl;
		return -1;
	}
    if (((ravensCount % 100 > 10) && (ravensCount < 20)) || (ravensCount == 0)) {
        std::cout << "В стае " << ravensCount << " ворон." << std::endl;
    } else if (ravensCount % 10 == 1) {
        std::cout << "В стае " << ravensCount << " ворона." << std::endl;
    } else {
        std::cout << "В стае " << ravensCount << " вороны." << std::endl;
    }
}
