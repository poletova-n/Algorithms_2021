#include <iostream>

char* to_lower(char* destination, char* source) {
	size_t i = 0;
	char letter;
	while ((letter = source[i]) != '\0') {
		destination[i] = letter;
		if ('A' <= letter && letter <= 'Z') {
			destination[i] ^= 32;
		}
		i++;
	}
	return destination;
}

int main () {
	char[] test = "A big BROWN fox JUMPS over THE lazy DOG.";
	size_t test_size = std::size(test);
	char* destination = new char[test_size+1];
	destination[test_size] = '\0';
	std::cout << test;
	std::cout << to_lower(test);
	return 0;
}