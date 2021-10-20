#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

const char* error_invalid_n = "The number of elements of the array must be a number. End of the program";

int Count (int size, int array[]);

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
            //std::cout << array[i] << std::endl;
        }
        int answer = Count(n,array);
        delete [] array;
        std::cout << "Number of positive elements:" << answer;
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}

int Count (int size, int array[])
{
    size = 10;
    int count = 0;
    int min = INT_MAX;
    srand(time(0));
    for (int k = 0; k < size; k++)
    {
        array[k] = rand();
    }
    int index = 0;
    for (int j = 0; j < size; j++)
    {
        if (array[j] < min)
        {
            min = array[j];
            index = j;
        }
    }
    for (int i = 0; i < index; i++)
    {
        if(array[i] > 0)
        {
            count ++;
        }
    }
    return count;
}


