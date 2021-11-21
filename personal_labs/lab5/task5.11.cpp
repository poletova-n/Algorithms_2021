//
// Created by reenie on 21.11.2021.
//
#include <iostream>
#include <fstream>

uint32_t count_lines_with_repeating_elements (int** matrix, size_t rows, size_t columns) {
	uint32_t counter = 0;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			for (size_t k = j+1; k < columns; k++) {
				if (matrix[i][j] == matrix[i][k]) {
					counter++;
					j = columns;
					break;
				}
			}
		}
	}
	return counter;
}

uint32_t find_line_with_longest_const_sequence (int** matrix, size_t rows, size_t columns) {
	size_t line = 0;
	uint32_t counter;
	uint32_t max_counter = 0;
	for (size_t i = 0; i < rows; i++) {
		counter = 0;
		for (size_t j = 1; j < columns; j++) {
			if (matrix[i][j] == matrix[i][j-1]) {
				counter++;
			} else if (counter != 0) {
				if (counter > max_counter) {
					max_counter = counter;
					line = i;
				} else {
					counter = 0;
				}
			}
		}
		if (counter > max_counter) {
			max_counter = counter;
			line = i;
		}
	}
	return line;
}

int** read_from_file(const char* path) {
	std::ifstream matrix_file(path);
	size_t rows;
	size_t columns;
	matrix_file >> rows;
	matrix_file >> columns;
	int** matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			matrix_file >> matrix[i][j];
		}
	}
	matrix_file.close();
	return matrix;
}

size_t get_rows(const char* path) {
	std::ifstream matrix_file(path);
	size_t rows;
	matrix_file >> rows;
	matrix_file.close();
	return rows;
}

size_t get_columns(const char* path) {
	std::ifstream matrix_file(path);
	size_t columns;
	matrix_file >> columns;
	matrix_file >> columns;
	matrix_file.close();
	return columns;
}

int main () {
	int** matrix = read_from_file("matrix_file.txt");
	size_t rows = get_rows("matrix_file.txt");
	size_t columns = get_columns("matrix_file.txt");
	std::cout << count_lines_with_repeating_elements(matrix, rows, columns) << std::endl;
	std::cout << find_line_with_longest_const_sequence(matrix, rows, columns) << std::endl;
	return 0;
}