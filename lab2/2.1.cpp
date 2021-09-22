#include <iostream>

int main()
{
    int a, b, c, maxN;
    std::cout << "Enter three numbers" << std::endl;
    std::cin >> a >> b >> c;
    if (std::cin.peek() != '\n')
    {
        std::cout << "Numbers must be entered. End of the program.";
    }
    else
    {
        if (a > b)
        {
            maxN = a;
            if (a < c)
            {
                maxN = c;
            }
        }
        else if (a < b)
        {
            maxN = b;
            if (b < c)
            {
                maxN = c;
            }
        }
        else
        {
            maxN = c;
        }
        std::cout << maxN;
    }
}