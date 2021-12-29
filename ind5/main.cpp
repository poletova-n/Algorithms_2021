#include <iostream>

#include "function.h"

#include "function2.h"

int main(){


    try {

        laba5::first();

        laba5::second();

    }

    catch (const std::exception& error) {

        std::cerr << error.what();

    }

    return 0;

}