// Вариант 3
// 
// Понятие выражение определено следующим образом:
// <выражение> ::= <терм> | <терм> +<выражение> | <терм> – <выражение>
// <терм> ::= <множитель> | <множитель> * <терм> | <множитель> / <терм>
// <множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
// <целое без знака> ::= <цифра> | <цифра> <целое без знака>
// <идентификатор> ::= <буква>
// <цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// <буква> ::= a | b | c | d | e | f | x | y | z

#include <iostream>
#include <ctype.h>

namespace expr {
	bool is_expression(const char*& str);		// <выражение> ::= <терм> | <терм> +<выражение> | <терм> – <выражение>
	bool is_term(const char*& str);				// <терм> ::= <множитель> | <множитель> * <терм> | <множитель> / <терм>
	bool is_multiplier(const char*& str);		// <множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
	bool is_integer(const char*& str);			// <целое без знака> ::= <цифра> | <цифра><целое без знака>
	bool is_identifier(const char*& str);		// <идентификатор> ::= <буква>
	bool is_digit(const char*& str);			// <цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
	bool is_letter(const char*& str);			// <буква> ::= a | b | c | d | e | f | x | y | z
}

int main() {
	setlocale(LC_ALL, "ru");

	const char* expressions[] = {
		"(123+123)/3",
		"(123e)",
		"(321/3)",
		"(321/3)e",
		"((321*345-342*e)/8)+5*e",
		"((321*345-342*e)/8*s)+5*e"
	};

	for (const char* expression : expressions) {
		std::cout << "String:\n";
		std::cout << "  " << expression << '\n';
		std::cout << (expr::is_expression(expression) ? "IS " : "is NOT ") << "an expression\n\n";
	}
	return 0;
}

namespace expr {
	int openedBracket = 0;
	bool is_letter(const char*& str) {
		if ((*str >= 'a' && *str <= 'f') || (*str >= 'x' && *str <= 'z')) {
			str++;
			return true;
		}
		return false;
	}
	bool is_digit(const char*& str) {
		if (std::isdigit(*str)) {
			str++;
			return true;
		}
		return false;
	}
	bool is_identifier(const char*& str) {
		return is_letter(str);
	}
	bool is_integer(const char*& str) {
		static bool wasFirstDigit = false;
		if (is_digit(str)) {
			wasFirstDigit = true;
			if (*str != '\0') {
				return is_integer(str);
			}
		}
		if (wasFirstDigit) {
			wasFirstDigit = false;
			return true;
		}
		else {
			return false;
		}
	}
	bool is_multiplier(const char*& str) {
		if (is_integer(str)) {
			return true;
		}
		else if (is_identifier(str)) {
			return true;
		}
		else if (*str == '(') {
			++openedBracket;
			if (is_expression(++str) && *str++ == ')') {
				return true;
			}
		}
		return false;
	}
	bool is_term(const char*& str) {
		if (is_multiplier(str)) {
			if ((*str == '*' || *str == '/') && *(str+1) != '\0' && *(str + 1) != '-' && *(str + 1) != '+' && is_term(++str)) {
				return true;
			}
			return true;
		}
		return false;
	}
	bool is_expression(const char*& str) {
		if (is_term(str)) {
			if (*str == '\0') {
				return true;
			}
			else if (*str == '+' || *str == '-') {
				return is_expression(++str);
			}
			else if (*str == ')' && openedBracket > 0) {
				--openedBracket;
				return true;
			}
		}

		return false;
	}
}