#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain integers.";

int main()
{
    std::cout << "Hello World!\n";

//    char a = 'а';
    //std::cout << a;

    int first = 0;
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
                std::cout << "Number of found cases: " << count;
                break;
            }
            if (first < second && second < third)
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
    }

    return 0;
}
