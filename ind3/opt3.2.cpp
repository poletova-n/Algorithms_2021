#include <iostream>

const char* ERROR_NOT_NUMBER = "You entered incorrect input";

void swap(int& a, int& b)
{
    int term = a;
    a = b;
    b = term;
}

int main()
{
    srand((unsigned) time(NULL));

    try
    {
        int size = 0;
        std::cout << "Enter the size array:";
        std::cin >> size;
        if(std::cin.fail() || std::cin.peek() != 10 || size < 0)
        {
            throw ERROR_INVALID_INPUT;
        }
        int *arr = new int[size];
        std::cout << "Before: ";
        for(int i = 0; i < size; ++i)
        {
            arr[i] = rand()%200 - 100;
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < size; ++i)
        {
            int smaller = i;
            for(int current = 0; current < size; ++current)
            {
                if(arr[smaller] < arr[current])
                {
                    swap(arr[smaller], arr[current]);
                }
            }
        }
        std::cout << "After: ";
        for(int i = 0; i < size; ++i)
        {
            std::cout << arr[i] << " ";
        }

        delete [] arr;
        return 0;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }

}