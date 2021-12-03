#include "string.h"

int main () {
	String str1("1abcdef");
	String str2("1abcdef");
	int i = str1.compare(str2);
	std::cout << i;
}
