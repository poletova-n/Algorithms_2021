#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain integers.";

int input();

int main()
{
        int first = 0;
        int second = 0;
        int third = 0;
        int count = 0;
        std::cout << "Enter numbers:" << std::endl;
        first = input();
        if(first == 0)
        {
            std::cout << "Number of strict local minima is " << count;
            return 0;
        }
        second = input();
        if(second == 0)
        {
            std::cout << "Number of strict local minima is " << count;
            return 0;
        }
        do
        {
            third = input();
            if(third == 0)
            {
                std::cout << "Number of strict local minima is " << count;
                break;
            }
            if(first > second && second < third)
            {
                count++;
            }
            first = second;
            second = third;
        }
        while (third != 0);
}

int input()
{
    try
    {
        int input = 0;
        std::cin >> input;
        if(std::cin.fail() && std::cin.peek() != 10)
        {
            throw ERROR_INVALID_INPUT;
        }
        return input;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        exit(-1);
    }
}