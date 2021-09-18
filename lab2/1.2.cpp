#include <iostream>

int main()
{
    int l1, l2, col1, col2;
    std::cout << "Enter line and column number of the rook: " << std::endl;
    std::cin >> l1 >> col1;
    std::cout << "Enter line and column number of another figure:" << std::endl;
    std::cin >> l2 >> col2;
    if ((l1==l2) or (col1 == col2))
    {
        std::cout << "The rook takes a figure.";
    }
    else
    {
        std::cout << "The rook doesn't take a figure.";
    }
}
