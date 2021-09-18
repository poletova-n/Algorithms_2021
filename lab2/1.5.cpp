#include <iostream>


int main()
{
    int l1, l2, col1, col2;
    std::cout << "Enter line and column number of the knight:" << std::endl;
    std::cin >> l1 >> col1;
    std::cout << "Enter line and column number of the knight:" << std::endl;
    std::cin >> l2 >> col2;
    if (((abs(l1-l2) == 1) and (abs(col1 - col2) == 2)) or ((abs(l1 - l2) == 2) and (abs(col1 - col2) == 1)))
    {
        std::cout << "The knight takes a figure.";
    }
    else
    {
        std::cout << "The knight doesn't takes a figure.";
    }
}
