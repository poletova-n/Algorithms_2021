//
// Created by reenie on 08.10.2021.
//

#include <vector>
#include <iostream>


int main() {
	uint32_t count = 0;
	int sum = 0;
	uint32_t positive_count = 0;
	uint32_t positive_sum = 0;
	int maximal = 0;
	uint32_t maximal_index = 0;
	int minimal = 0;
	uint32_t minimal_index = 0;
	int temp = 0; // Временное значение для входа в функцию
	while ((std::cin >> temp) && (temp != 0)) { // Пока читается поток и пока временное значение не равно нулю.
		count++;
		sum += temp;
		if (temp > 0) {
			positive_count++;
			positive_sum += temp;
		}
		if (maximal < temp) {
			maximal_index = count;
			maximal = temp;
		}
		if (minimal > temp) {
			minimal_index = count;
			minimal = temp;
		}
	}
	std::cout << "Сумма всех введенных чисел: " << sum;
	std::cout << "Cреднее арифметическое всех введенных чисел: " << static_cast<double>(sum/count);
	std::cout << "Cреднее арифметическое всех положительных введенных чисел: " << static_cast<double>(sum/count);
}