#include <iostream>

const char* error_coordinate_not_number = "The coordinates of the figures must be numbers. End of the program.";
const char* error_invalid_coordinates = "The coordinates of the figures must be greatest than zero less than nine. End of the program.";

int main()
{
    int l1, col1;
    std::cout << "Enter line and column number of the bishop: " << std::endl;
    std::cin >> l1 >> col1;
    try
    {
        if (std::cin.peek() != '\n')
        {
            throw error_coordinate_not_number;
        }
        if (l1 < 1 or col1 < 1 or l1 > 8 or col1 > 8)
        {
            throw error_invalid_coordinates;
        }
        for (int i = 1; i < 9; i++)
        {
            for (int j = 1; j < 9; j++)
            {
                if (abs(l1-i) == abs(col1-j))
                {
                    std::cout << "(" << i << ";" << j << ")";
                }
            }
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
    }
}
