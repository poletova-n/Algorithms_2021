#include <iostream>

int main()
{
    int x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the first point:" << std::endl;
    std::cin >> x1 >> y1;
    if (std::cin.peek() != '\n')
    {
        std::cout << "The coordinates of the first point must be numbers. End of the program.";
    }
    else
    {
        std::cout << "Enter the coordinates of the second point:" << std::endl;
        std::cin >> x2 >> y2;
        if (std::cin.peek() != '\n')
        {
            std::cout << "The coordinates of the second point must be numbers. End of the program.";
        }
        else
        {
            if (((x1 * x2) > 0) && ((y1 * y2) > 0))
            {
                std::cout << "Yes";
            }
            else
            {
                std::cout << "No";
            }
        }
    }
}