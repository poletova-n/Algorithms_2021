#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input must only contain numbers greater than 0 and less than 9.";

int main()
{
    try {
        int x = 0, y = 0;
        std::cout << "Enter figure coordinates:";
        std::cin >> x >> y;
        if (std::cin.fail() || std::cin.peek() != 10 || x > 8 || y > 8 || x < 1 || y < 1)
        {
            throw ERROR_INVALID_INPUT;
        }
        std::cout << "Positions under figure's attack:";
        std::cout << std::endl;
        for (int i = 1; i < 9; ++i)
        {
            if(i != y)
            {
                std::cout << x << " " << i << "; ";
            }
        }
        std::cout << std::endl;
        for (int i = 1; i < 9; ++i) {
            if(i != x)
            {
                std::cout << i << " " << y << "; ";
            }
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }

}
