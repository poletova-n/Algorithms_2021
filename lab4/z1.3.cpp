#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain positive numbers";

int main()
{
    try {
        double sum = 0;
        int c = 0;
        double input = 0;
        do
        {
            std::cout << "Enter number:";
            std::cin >> input;
            if(std::cin.fail() || std::cin.peek() != 10 || input <= 0)
            {
                throw ERROR_INVALID_INPUT;
            }
            sum += input;
            c++;
        }
        while (input != 0);
        c--;
        std::cout << "Average: " << sum / c;
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}