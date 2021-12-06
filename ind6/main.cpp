#include "string.h"
#include "bankcard.h"

int main () {
	String str = "str1";
	String str2 = "str2";
	std::cout << "pass\n" << str << "end\n";
	str = std::move(str2);
	std::cout << str << "\n";
}
