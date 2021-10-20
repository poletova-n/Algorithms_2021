#include <iostream>
#include "counter.h"

int main()
{
    const int size = 10;
    int array[size] = {145, -22, 93, -14, -5, 30, 99, -708, 111, 3};
    std::cout << "Number of positive elements: " << counter(size,array);
}


