#include <cstdio>

char* to_lower(char* destination, const char* source) {
	size_t i = 0;
	char letter;
	while ((letter = source[i]) != '\0') {
		destination[i] = letter;
		if ('A' <= letter && letter <= 'Z') {
			destination[i] ^= 0b100000;
		}
		i++;
	}
	return destination;
}

size_t strlen(const char* source) {
	size_t i = 0;
	while (source[i] != '\0') {
		i++;
	}
	return i;
}

int main () {
	char* input = new char;
	size_t input_size = -1;
	getline(&input, &input_size, stdin);
	input_size = strlen(input);

	char* destination = new char[input_size+1];
	destination[input_size] = '\0';

	printf("%s", to_lower(destination, input));
	return 0;
}