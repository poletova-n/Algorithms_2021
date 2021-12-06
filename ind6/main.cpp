#include "string.h"
#include "bankcard.h"

int main () {
	String str1 = "str1";
	String str2 = "str2";
	std::cout << "\t" << str1;
	str1 = std::move(str2);
	std::cout << str1;
}
