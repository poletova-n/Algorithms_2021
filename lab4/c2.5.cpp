#include <iostream>

const char* error_not_number = "The side of the triangle must be numbers. End of the program.";
const char* error_less_zero = "The side of the square must be greatest than zero. End of the program.";

int main()
{
    int N;
    std::cout << "Enter the side of the triangle: " << std::endl;
    std::cin >> N;
    try
    {
        if (std::cin.peek() != '\n')
        {
            throw error_not_number;
        }
        if (N < 0)
        {
            throw error_less_zero;
        }
        for (int i = 1; i < N+1; i++)
        {
            for (int j = 1; j < i+1; j++)
            {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }


