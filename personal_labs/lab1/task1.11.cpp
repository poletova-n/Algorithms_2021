#include <iostream>


int main() {
	int previous = 0;
	int count = 0;
	int temp = 0;
	std::cin >> previous;
	while (std::cin >> temp && temp != 0) {
		if (temp % previous == 0) {
			count++;
		}
		previous = temp;
	}
	std::cout << count;
}