#include <iostream>

//
// Created by reenie on 26.09.2021.
//
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
	int x1, y1, x2, y2;
	std::cout << "Введите x координату точки 1: ";
	x1 = get_int();
	std::cout << "Введите y координату точки 1: ";
	y1 = get_int();
	std::cout << "Введите x координату точки 2: ";
	x2 = get_int();
	std::cout << "Введите y координату точки 2: ";
	y2 = get_int();
	if ((x1*x2 >= 0) && (y1*y2 >= 0)) {
		std::cout << "Точки лежат в одной плоскости";
	} else {
		std::cout << "Точки не лежат в одной плоскости";
	}
}