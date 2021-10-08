//
// Created by reenie on 08.10.2021.
//

#include <vector>
#include <iostream>


int main() {
	int count = 0;
	int sum = 0;
	uint32_t positive_count = 0;
	uint32_t positive_sum = 0;
	int maximal = 0;
	uint32_t maximal_index = 0;
	uint32_t minimal = -1;
	uint32_t minimal_index = 0;

	int temp = 0;
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
		if (temp > 0 && minimal > temp) {
			minimal_index = count;
			minimal = temp;
		}
	}
	float average = float(sum)/float(count);
	float positive_average = float(positive_sum)/float(positive_count);

	std::cout << "Сумма всех введенных чисел: " << sum << std::endl;
	std::cout << "Cреднее арифметическое всех введенных чисел: " << average << std::endl;
	std::cout << "Cреднее арифметическое всех положительных введенных чисел: " << positive_average << std::endl;
	std::cout << "Максимальное значение и его номер среди всех введенных чисел: " << maximal << " " << maximal_index << std::endl;
	std::cout << "Минимальное положительное значение и его номер среди всех введенных чисел: " << static_cast<int>(maximal) << " " << minimal_index << std::endl;
	return 0;
}