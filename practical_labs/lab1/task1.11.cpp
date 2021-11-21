#include <iostream>
#include <iomanip>
#include <vector>

bool isLetter(char*& str) {
	if ('a' <= *str && *str <= 'e') {
		str++;
		return true;
	}
	return false;
}

bool isDigit(char*& str) {
	if ('0' <= *str && *str <= '9') {
		str++;
		return true;
	}
	return false;
}

bool isID(char*& str) {
	if (isLetter(str)) {
		return true;
	}
	return false;
}

bool isUInt(char*& str) {
	if (isDigit(str)) {
		isUInt(str);
		return true;
	}
	return false;
}

bool isFactor(char*& str) {
	char* past_state = str;

	if (isUInt(str)) {
		return true;
	}

	str = past_state;

	if (isID(str)) {
		return true;
	}

	return false;
}

bool isTerm(char*& str) {
	if (isFactor(str)) {
		if (*str == '/' || *str == '*') {
			str++;
			return isTerm(str);
		} else {
			return true;
		}
	}
	return false;
}

bool isExpression (char*& str) {
	if (isTerm(str)) {
		if (*str == '+' || *str == '-') {
			str++;
			return isExpression(str);
		} else {
			return *str == '\0';
		}
	}
	return false;
}

int main () {
	char* test = "a";
	isFactor(test);
	std::vector<char*> expressions = {
			"a",
			"1+a",
			"a*b-2",
			"5+5",
			"1\\a",
			"1/1",
			"5.5E+2",
			"-5.123E-123",
			"12.3E-12"
	};
	for (auto& expr: expressions) {
		std::cout << std::right << std::setw(16);
		std::cout << expr << " " << std::left << (isExpression(expr) ? "true" : "false") << std::endl;
	}
}