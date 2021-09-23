#include <iostream>
const char* error_invalid_number = "Numbers must be entered. End of the program";

int main()
{
    int sum = 0, num = -1, count = 0;
    double aver;
    try
    {
        std::cout << "Enter numbers: " << std::endl;
        while (num != 0)
        {
            std::cin >> num;
            if (std::cin.peek() != '\n')
            {
                throw error_invalid_number;
            }
            else if (num > 0)
            {
                sum += num;
                count ++;
                aver = (double(sum)/count);
            }

        }
        std::cout << "Average of all positive numbers: " << aver;
    }
    catch (const char *error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}