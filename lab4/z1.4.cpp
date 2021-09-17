#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain numbers.";

int main()
{
    try {
        double max = std::numeric_limits<double>::min();
        double maxC = 0;
        double input = 100;
        int c = 0;
        do
        {
            std::cout << "Enter number:";
            std::cin >> input;
            c++;
            if(std::cin.fail() || std::cin.peek() != 10)
            {
                throw ERROR_INVALID_INPUT;
            }
            if(input >= max)
            {
                max = input;
                maxC = c;
            }
        }
        while (input != 0);
        c--;
        std::cout << "Max number is " << max << " on " << maxC << " position.";
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}
