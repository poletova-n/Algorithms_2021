#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input.txt must only contain integers.";

int main()
{
    try {
        int min = std::numeric_limits<int>::max();
        int minC = 0;
        int input = 100;
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
            if(input <= min && input != 0)
            {
                min = input;
                minC = c;
            }
        }
        while (input != 0);
        c--;
        std::cout << "Min number is " << min << " on " << minC << " position.";
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}
