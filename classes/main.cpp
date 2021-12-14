#include <iostream>

#include "func.h"

int main() {

    const char* str = "-123E+4";

    std::cout << funcs::isReal(str) << std::endl;

    std::cout << funcs::isReal("-.12345432123454321E+192374829") << std::endl;

    std::cout << funcs::isReal("1E1") << std::endl;

    return 0;

}