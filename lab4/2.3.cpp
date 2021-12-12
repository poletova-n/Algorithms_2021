#include <iostream>
#include <string>

const std::string ERROR_NOT_NUMBER = "You entered not the number";
const std::string ERROR_NOT_POSITIVE_NUMBER = "You entered not positive number";

int main()
{
    try
    {
        int n;
        std::cout << "Enter the number: ";
        std::cin >> n;

        if (std::cin.fail() || std:: cin.peek() != 10)
        {
            throw ERROR_NOT_NUMBER;
        }
        if (n < 0)
        {
            throw ERROR_NOT_POSITIVE_NUMBER;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << std::endl;
                for (int j = 0; j < n; j++)
                {
                    std::cout << " * ";
                }
            }
        }

    }
    catch (const std::string& error)
    {
        std::cerr << std::endl << error << std:: endl;
        return -1;
    }
}