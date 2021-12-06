#include "string.h"
#include "bankcard.h"

int main () {
	String str1 = "str1";
	String str2 = "str2";
	std::cout << str1 << "\n";
	str1 = str2;
	std::cout << str1 << "\n";
}
