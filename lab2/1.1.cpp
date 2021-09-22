#include <iostream>

int main()
{
    int year;
    std::cout << "Enter year: " << std::endl;
    std::cin >> year;
    if (std::cin.peek() != '\n')
    {
        std::cout << "The year must be a number. End of the program.";
    }
    else
    {
        if (((year % 4 == 0) or (year % 400 == 0)) and (year % 100 != 0))
        {
            std::cout << "This is a leap year.";
        }
        else
        {
            std::cout << "This isn't a leap year.";
        }
    }
    return 0;
}