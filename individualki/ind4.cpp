#include <iostream>
#include <iomanip>
#include <fstream>

namespace errors_msg {
	const char* STRING_SIZE = "Error! string size expected more than 0!";
}

enum class errors {
	STRING_SIZE,
};

char* function(char* const destination, const char* source);	

int main() {
	setlocale(LC_ALL, "ru");

	const int MAX_INT_LENGTH = static_cast<int>(ceil(log10(std::numeric_limits<int>::max())));

	int sizeofStr = 0;
	int fileSize = 0;

	std::ifstream fin("fileIn.txt");
	std::ofstream fout("fileOut.txt");
	
	char* str = nullptr;
	char* destination = nullptr;
	char* num = nullptr;

	try {
		while (!fin.eof()) {
			num = new char[MAX_INT_LENGTH];
			fin.getline(num, MAX_INT_LENGTH, '\n');
			sizeofStr = std::atoi(num);
			if (sizeofStr == 0) {
				break;
			}
			else if (sizeofStr < 0) {
				throw errors::STRING_SIZE;
			}
			sizeofStr++;
			str = new char[sizeofStr];
			fin.getline(str, sizeofStr);
			destination = new char[sizeofStr];
			function(destination, str);
			fout << destination << std::endl;
			delete[] num;
			delete[] str;
			delete[] destination;
		}
	}
	catch (errors errorNum) {
		delete[] num;
		delete[] str;
		delete[] destination;
		switch (errorNum) {
		case errors::STRING_SIZE:
			std::cerr << errors_msg::STRING_SIZE << std::endl;
			return 1;
		}
	}

	return 0;
}

char* function(char* const destination, const char* source) {
	int newI = 0;
	char currSymbol = source[0];
	for (int i = 0; source[i] != '\0'; i++) {
		currSymbol = source[i];
		if (!((currSymbol >= 'A' && currSymbol <= 'Z') || (currSymbol >= 'a' && currSymbol <= 'z'))) {
			destination[newI] = currSymbol;
			newI++;
		}
	}
	destination[newI] = '\0';

	return destination;
}
