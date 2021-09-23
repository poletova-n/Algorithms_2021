#include <iostream>
const char* error_invalid_number = "Numbers must be entered. End of the program";

int main()
{
    int sum = 0, num = -1, count = -1;
    double aver;
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
            sum += num;
            aver = (double(sum)/count);
        }
        std::cout << "Average of all numbers: " << aver;
    }
    catch (const char *error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}
