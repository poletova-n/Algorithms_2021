#include <iostream>

int main()
{
    int a, b, c;
    std::cout << "Enter three numbers" << std::endl;
    std::cin >> a >> b >> c;
    if (std::cin.peek() != '\n')
    {
        std::cout << "Numbers must be entered. End of the program.";
    }
    else
    {
        if ((a % 2 == 0 || b % 2 == 0 || c % 2 == 0) && ((a % 2 != 0 || b % 2 != 0 || c % 2 != 0)))
        {
            std::cout << "Yes";
        }
        else
        {
            std::cout << "No";
        }
        return 0;
    }
}
