#include <iostream>

int main() {
	int a, b, c = 0;
	std::cout << "Введите 3 числа: ";
	std::cin >> a >> b >> c;
	int max = std::max(std::max(a,b), c);
	std::cout << max;
}