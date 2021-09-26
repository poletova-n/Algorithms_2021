#include <iostream>
#include <vector>

int get_int() {
	int temp = 0;
	std::cin >> temp;
	if (std::cin.fail() or std::cin.peek() != '\n') {
		std::cout << "Коэффициент должен быть целочисленным.\n";
		std::exit(1);
	}
	return temp;
}

int main () {
	int a, b, c;
	std::cout << "Введите первое число: ";
	a = get_int();
	std::cout << "Введите второе число: ";
	b = get_int();
	std::cout << "Введите третье число: ";
	c = get_int();
	std::vector list = {a,b,c};
	int counter = 0;
	for (int i = 0; i < list.size(); i++) {
		for (int j = i; j < list.size(); j++) {
			if (list[i] == list[j]) {
				counter++;
			}
		}
	}
	counter = (counter / 2) - counter % 2;
	std::cout << counter;
}