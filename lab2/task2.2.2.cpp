#include <iostream>
#include <vector>

bool reversed_sort(int first, int second) {
	return first > second;
}

int main() {
	int a, b, c = 0;
	std::cout << "Введите 3 числа: ";
	std::cin >> a >> b >> c;
	std::vector<int> sorted_list = {a, b, c};
	std::sort(sorted_list.begin(), sorted_list.end(), reversed_sort);
	for (int i : sorted_list) {
		std::cout << i << " ";
	}
}
