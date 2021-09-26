//
// Created by reenie on 26.09.2021.
//

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

int main() {
	int a, b, c;
	std::cout << "Введите первое число: ";
	a = get_int();
	std::cout << "Введите второе число: ";
	b = get_int();
	std::cout << "Введите третье число: ";
	c = get_int();
	int i = 0;
	std::vector list = {a,b,c};
	bool odd_flag = false;
	bool even_flag = false;
	while ((!odd_flag || !even_flag) && (i < list.size())) {
		if (list[i++] % 2 == 0) {
			even_flag = true;
		} else {
			odd_flag = true;
		}
	}
	if (even_flag && odd_flag) {
		std::cout << "ДА";
	} else {
		std::cout << "НЕТ";
	}
}
