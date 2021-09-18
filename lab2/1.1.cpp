#include <iostream>

int main()
{
    int year;
    std::cout << "Enter year: " << std::endl;
    std::cin >> year;
    if ((year % 4 == 0) and (year % 100 != 0) and (year % 400 == 0))
    {
        std::cout << "This is a leap year.";
    }
    else
    {
        std::cout << "This isn't a leap year.";
    }
    return 0;
}