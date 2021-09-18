#include <iostream>

int main()
{
    int l1, l2, col1, col2;
    std::cout << "Enter line and column number of the queen:" << std::endl;
    std::cin >> l1 >> col1;
    std::cout << "Enter line and column number of the queen:" << std::endl;
    std::cin >> l2 >> col2;
    if ((abs(l1 - l2) == abs(col1 - col2)) or (l1==l2) or (col1 == col2))
    {
        std::cout << "The queen takes a figure.";
    }
    else
    {
        std::cout << "The queen doesn't takes a figure.";
    }
}