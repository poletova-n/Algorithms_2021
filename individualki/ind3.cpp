#include <iostream>
#include <random>
#include <fstream>

namespace errorMsg {
	const char* NO_MAX_NUM = "Error! There is no numbers occuring more than 1 time!\n";
	const char* INCORRECT_RANDOM_SWEEP = "Error! Expected sweep of random less or equal to RAND_SIZE\n";
	const char* INCORRECT_INPUT = "Error! Expected an integer number!\n";
	const char* INCORRECT_BORDERS = "Error! Border has to be not equal!\n";
	const char* INCORRECT_ARRAY_SIZE = "Error! Array size must be more than 0!\n";
};

enum class errors {
	NO_MAX_NUM,
	INCORRECT_INPUT,
	INCORRECT_RANDOM_SWEEP,
	INCORRECT_BORDERS,
	INCORRECT_ARRAY_SIZE
};

template <class T>
void printArray(T arr[], int arrSize) {
	std::cout << '[' << ' ';
	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << ']' << '\n';
}

int findMax(const int arr[], int arrSize) {
	if (arrSize <= 0) {
		throw errors::INCORRECT_ARRAY_SIZE;
	}
	int maxNum = 0;
	bool isMaxNumInitialized = false;
	for (int i = 0; i < arrSize && !isMaxNumInitialized; i++) {
		int count = 0;
		for (int j = 0; j < arrSize && !isMaxNumInitialized; j++) {
			if (arr[j] == arr[i]) {
				count += 1;
			}
			if (count > 1) {
				maxNum = arr[i];
				isMaxNumInitialized = true;
			}
		}
	}

	if (!isMaxNumInitialized) {
		throw errors::NO_MAX_NUM;
	}

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > maxNum) {
			bool isOccuredMoreThanOne = false;
			int count = 0;
			for (int j = 0; j < arrSize && !isOccuredMoreThanOne; j++) {
				if (arr[j] == arr[i]) {
					count += 1;
				}
				if (count > 1) {
					isOccuredMoreThanOne = true;
				}
			}
			if (isOccuredMoreThanOne) {
				maxNum = arr[i];
			}
		}
	}

	return maxNum;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	// initialized array
	try {
		const int SIZE = 8;
		if (SIZE <= 0) {
			throw errors::INCORRECT_ARRAY_SIZE;
		}
		int arr[SIZE] = { 1, 1, 5, 6, 7, 8, 9, 9 };

		std::cout << "Initialized array: " << std::endl;
		printArray(arr, SIZE);
		std::cout << findMax(arr, SIZE) << std::endl;
	}
	catch (errors errorNum) {
		switch (errorNum) {
		case errors::NO_MAX_NUM:
			std::cerr << errorMsg::NO_MAX_NUM;
			break;
		case errors::INCORRECT_ARRAY_SIZE:
			std::cerr << errorMsg::INCORRECT_ARRAY_SIZE;
			return 5;
		}
	}

	std::cout << std::endl;

	// dynamic memory array
	try {
		int dynSize = 0;
		std::cout << "Enter a size of dynamic memory array: ";
		std::cin >> dynSize;
		if (!std::cin.good()) {
			throw errors::INCORRECT_INPUT;
		}
		if (dynSize <= 0) {
			throw errors::INCORRECT_ARRAY_SIZE;
		}
		int lowerBound;
		int higherBound;
		std::cout << "Enter borders of random numbers for array: ";
		std::cin >> lowerBound >> higherBound;
		if (!std::cin.good()) {
			throw errors::INCORRECT_INPUT;
		}
		if (lowerBound > higherBound) {
			int memory = lowerBound;
			lowerBound = higherBound;
			higherBound = lowerBound;
		}
		if (lowerBound == higherBound) {
			throw errors::INCORRECT_BORDERS;
		}
		if (higherBound - lowerBound > RAND_MAX) {
			throw errors::INCORRECT_RANDOM_SWEEP;
		}
		int* dynArr = new int[dynSize];
		for (int i = 0; i < dynSize; i++) {
			dynArr[i] = rand() % (higherBound - lowerBound + 1) + lowerBound;
		}

		std::cout << "Array in dynamic memory: " << std::endl;
		printArray(dynArr, dynSize);
		std::cout << findMax(dynArr, dynSize) << std::endl;

		delete[] dynArr;
	}
	catch (errors errorNum) {
		switch (errorNum) {
		case errors::NO_MAX_NUM:
			std::cerr << errorMsg::NO_MAX_NUM;
			break;
		case errors::INCORRECT_INPUT:
			std::cerr << errorMsg::INCORRECT_INPUT;
			return 2;
		case errors::INCORRECT_BORDERS:
			std::cerr << errorMsg::INCORRECT_BORDERS;
			return 4;
		case errors::INCORRECT_RANDOM_SWEEP:
			std::cerr << errorMsg::INCORRECT_RANDOM_SWEEP;
			return 3;
		case errors::INCORRECT_ARRAY_SIZE:
			std::cerr << errorMsg::INCORRECT_ARRAY_SIZE;
			return 5;
		}
	}

	std::cout << std::endl;

	// from-file array
	std::ifstream fin("file.txt");
	while (!fin.eof()) {
		try {
			int arraySize;
			fin >> arraySize;
			if (fin.fail()) {
				std::cout << "File ended / error reading an array size" << std::endl;
				break;
			}
			if (arraySize <= 0) {
				throw errors::INCORRECT_ARRAY_SIZE;
			}
			int* fileArray = new int[arraySize];
			for (int i = 0; i < arraySize; i++) {
				fin >> fileArray[i];
				if (fin.fail()) {
					throw errors::INCORRECT_INPUT;
				}
			}

			std::cout << "File array: " << std::endl;
			printArray(fileArray, arraySize);
			std::cout << findMax(fileArray, arraySize) << std::endl;

			delete[] fileArray;
		}
		catch (errors errorNum) {
			switch (errorNum) {
			case errors::NO_MAX_NUM:
				std::cerr << errorMsg::NO_MAX_NUM;
				break;
			case errors::INCORRECT_INPUT:
				std::cerr << errorMsg::INCORRECT_INPUT;
				return 2;
			case errors::INCORRECT_ARRAY_SIZE:
				std::cerr << errorMsg::INCORRECT_ARRAY_SIZE;
				return 5;
			}
		}
	}

	return 0;
}
