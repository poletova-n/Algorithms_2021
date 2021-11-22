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
	return isUInt(str) || isID(str);
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
	std::vector<char*> expressions = {
			"a",
			"1+a",
			"a*b-2",
			"5+5",
			"1\\a",
			"1+2-3/7*2*0/2-9/9",
			"5.5E+2",
			"-5.123E-123",
			"12.3E-12"
	};
	int i = 1;
	for (auto& expr: expressions) {
		std::cout << "№" << i++;
		std::cout << std::right << std::setw(24) << expr  << " : ";
		std::cout << std::left  << (isExpression(expr) ? "true" : "false") << std::endl;
	}
}