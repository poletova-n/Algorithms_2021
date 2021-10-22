#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

const char* ERROR_INVALID_INPUT = "Either a non-integer positive number was entered, or a non-number was entered, end of the program!\a"; \
const char* ERROR_INVALID_FILE_NUMBER = "An error occurred while reading from the file. Either the file was not found, or the sequence number not a positive integer!\a";

int MyFunc(int array[], int count)
{
    int countThree = 1, countMax = 0;
    for (int i = 1; i < count; i++)
    {
        if (array[i - 1] > array[i])
        {
            countThree++;
        }
        else
        {
            countMax = std::max(countMax, countThree);
            countThree = 1;
        }
        countMax = std::max(countMax, countThree);
    }
    return countMax;
}

int main()
{
    const int size = 5;
    int arrayOne[size] = { 1, 6845, 654, 888, 789 };
    int countOne = 1, countMaxOne = 0;

    countMaxOne = MyFunc(arrayOne, size);
    std::cout << "Longest monotonically decreasing fragment length the sequence from the initialized array is " << countMaxOne << std::endl << std::endl;

    int arrsize = 0;
    try
    {
        std::cout << "Enter the number of elements in a dynamic array: ";
        std::cin >> arrsize;
        srand(time(0));
        if ((!std::cin) or std::cin.fail() or (std::cin.peek() != 10))
        {
            throw ERROR_INVALID_INPUT;
        }
        int* arrayTwo = new int[arrsize];

        for (int i = 0; i < arrsize; i++)
        {
            arrayTwo[i] = rand() % 30001 - 15000;
        }
        int countTwo = 1, countMaxTwo = 0;
        countMaxTwo = MyFunc(arrayTwo, arrsize);

        if (countMaxTwo != 1)
        {
            std::cout << "Longest monotonically decreasing fragment length a sequence from a dynamic array is " << countMaxTwo << std::endl << std::endl;;
        }
        else
        {
            std::cout << "There is no monotonically decreasing fragment in the sequence!" << std::endl;
        }
        delete[] arrayTwo;
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }

    int arrsizes = 0, countThree = 0, countMaxThree = 0, k = 0;;

    std::ifstream input("input.txt");

    try
    {
        while (!input.eof())
        {
            countThree = 1;
            arrsizes = 0;
            countMaxThree = 1;
            input >> arrsizes;
            k++;
            if (arrsizes == 0)
            {
                return 0;
            }
            if ((!input) or input.fail() or (input.peek() != 10))
            {
                throw ERROR_INVALID_FILE_NUMBER;
            }

            int* arrayThree = new int[arrsizes];

            for (int i = 0; i < arrsizes; i++)
            {
                input >> arrayThree[i];
                if ((!input) or input.fail() or (input.peek() != 10))
                {
                    delete[] arrayThree;
                    throw ERROR_INVALID_FILE_NUMBER;
                }

            }

            countMaxThree = MyFunc(arrayThree, arrsizes);

            std::cout << k << " array : ";

            if (countMaxThree > 1)
            {
                std::cout << "The longest length of a monotonically decreasing fragment from a file is " << countMaxThree << std::endl;
            }
            else
            {
                std::cout << "There is no monotonically decreasing fragment in the sequence from file!" << std::endl;
            }
            delete[] arrayThree;
        }
        input.close();
    }
    catch (const char* error)
    {
        std::cerr << error;
        return -1;
    }
    return 0;
}
