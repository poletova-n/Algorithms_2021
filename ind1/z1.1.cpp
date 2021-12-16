#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input.txt must only contain integers.";

int main()
{

    char a = 'а';

    std::cout << a;
    /*int first = 0;
    int second = 0;
    int third = 0;
    int count = 0;

    std::cout << "Enter numbers:" << std::endl;

    try
    {
        do
        {
            std::cin >> third;
            if (std::cin.fail())
            {
                throw ERROR_INVALID_INPUT;
            }

            if (third == 0)
            {
                if (std::cin.peek() != 10)
                {
                    throw ERROR_INVALID_INPUT;
                }
                std::cout << "Number of strict local minima " << count;
                break;
            }

            std::cout << std::cin.peek() << std::endl;

            if (first > second && second < third)
            {
                count++;
            }

            first = second;
            second = third;
        }
        while (third != 0);
    }
    catch(const char *error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }*/
}

