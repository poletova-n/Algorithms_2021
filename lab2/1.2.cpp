#include <iostream>

int main()
{
    int l1, l2, col1, col2;
    std::cout << "Enter line and column number of the rook: " << std::endl;
    std::cin >> l1 >> col1;
    if (std::cin.peek() != '\n')
    {
        std::cout << "The coordinates of the figures must be numbers. End of the program.";
    }
    else
    {
        std::cout << "Enter line and column number of another figure:" << std::endl;
        std::cin >> l2 >> col2;
        if (std::cin.peek() != '\n')
        {
            std::cout << "The coordinates of the figures must be numbers. End of the program.";
        }
        else
        {
            if ((l1==l2) or (col1 == col2))
            {
                std::cout << "The rook takes a figure.";
            }
            else
            {
                std::cout << "The rook doesn't take a figure.";
            }
        }
    }
}
