#include <iostream>
const char* error_invalid_number = "Numbers must be entered. End of the program";

int main()
{
    int num = -1, count = 0, minN = INT_MAX, ser_num = 0;
    try
    {
        std::cout << "Enter numbers: " << std::endl;
        while (num != 0)
        {
            std::cin >> num;
            count ++;
            if (std::cin.peek() != '\n')
            {
                throw error_invalid_number;
            }
            if ((num < minN) and (num > 0))
            {
                minN = num;
                ser_num = count;
            }
        }
        std::cout << "Minimum positive numbers: " << minN<< std::endl;
        std::cout << "Serial number: " << ser_num;
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}
