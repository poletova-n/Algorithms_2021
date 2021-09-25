#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain integers.";

int main()
{
    try
    {
        int first = 0;
        int second = 0;
        int third = 1;
        int count = 0;
        std::cin >> first;
        if(std::cin.fail() && std::cin.peek() != 10)
        {
            throw ERROR_INVALID_INPUT;
        }
        if(first == 0)
        {
            std::cout << count;
            return 0;
        }
        std::cin >> second;
        if(std::cin.fail() && std::cin.peek() != 10)
        {
            throw ERROR_INVALID_INPUT;
        }
        if(second == 0)
        {
            std::cout << count;
            return 0;
        }
        while (third != 0)
        {
            std::cin >> third;
            if(std::cin.fail() && std::cin.peek() != 10)
            {
                throw ERROR_INVALID_INPUT;
            }
            if(third == 0)
            {
                std::cout << count;
                break;
            }
            if(first > second && second < third)
            {
                count++;
            }
            first = second;
            second = third;
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}