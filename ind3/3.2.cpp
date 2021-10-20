#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "counter.h"

const char* error_invalid_n = "The number of elements of the array must be a number. End of the program";

int main()
{
    try
    {
        int n;
        std::cout << "Enter the number of elements of the array: " << std::endl;
        std::cin >> n;
        int *array = new int [n];
        if (std::cin.peek() != '\n')
        {
            throw error_invalid_n;
        }
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            array[i] = rand() ;
            std::cout << array[i] << std::endl;
        }
        std::cout << "Number of positive elements:" << counter(n,array) << std::endl;
        delete [] array;
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}


