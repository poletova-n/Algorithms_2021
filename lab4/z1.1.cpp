#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input.txt must only contain integers";

int main()
{
    try
    {
        int sum = 0;
        int input = 0;
        do
        {
            std::cout << "Enter number:";
            std::cin >> input;
            if(std::cin.fail() || std::cin.peek() != 10)
            {
                throw ERROR_INVALID_INPUT;
            }
            sum += input;
        }
        while (input != 0);
        std::cout << "Sum: " << sum;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}
