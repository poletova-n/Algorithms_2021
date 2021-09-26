#include <iostream>

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
	int max = std::max(std::max(a,b), c);
	std::cout << "Число " << max << " максимальное";
}