#include <iostream>

const char* error_not_number = "The side of the rhombus must be numbers. End of the program.";
const char* error_less_zero = "The side of the rhombus must be greatest than zero. End of the program";

int main()
{
    int N, space;
    std::cout << "Enter the side of the rhombus: " << std::endl;
    std::cin >> N;
    try
    {
        space = N-1;
        if (std::cin.peek() != '\n')
        {
            throw error_not_number;
        }
        if (N < 0)
        {
            throw error_less_zero;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < space; j++)
            {
                std::cout << " ";
            }
            for (int j = 0; j < i+1; j++)
            {
                std::cout << "* ";
            }

            std::cout << std::endl;
            space--;

        }
        space = 0;
        for (int i = N; i > 0; i--)
        {

            for (int j = 0; j < space+1; j++)
            {
                std::cout << " ";
            }
            for (int j = 1; j < i; j++)
            {
                std::cout << "* ";
            }
            std::cout << std::endl;
            space++;

        }
    }
    catch (const char *error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}