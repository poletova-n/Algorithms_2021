#include <iostream>
const char* error_not_number = "Only numbers must be entered. End of the program";

int main()
{
    try
    {
        int num = INT_MIN, fMax = INT_MIN,sMax = INT_MIN;
        std::cout << "Enter numbers: "<< std::endl;
        while (num != 0)
        {
            std::cin >> num;
            if (std::cin.peek() != '\n')
            {
                throw error_not_number;
            }
            if (num >= fMax)
            {
                sMax = fMax;
                fMax = num;
            }
            else if(num > sMax)
            {
                sMax = num;
            }
        }
        std::cout << "Second maximum number:" << sMax;
    }
    catch(const char* error)
    {
        std::cerr << std:: endl << error <<std::endl;
    }
}
