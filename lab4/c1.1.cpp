#include <iostream>
const char* error_invalid_number = "Numbers must be entered. End of the program."

int main()
{
    int sum = 0, num = 0;
    try
    {
        std::cout << "Enter numbers: " <<std::endl;
        while (num != 0)
        {
            std::cin >> num;
            if (std::cin.peek() != '\n')
            {
                throw error_invalid_number;
            }
            else
            {
                sum += num;
            }
        }
        catch (const char* error)
        {
            std::cerr << std::endl << error << std::endl;
        }
    }
    std::cout << "Sum of all numbers: " << sum;
}