#include <iostream>

const char* ERROR_INVALID_INPUT = "Error: input.txt must only contain numbers greater than 0 and less than 9.";

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
        int addX = 1, addY = 1, c = 0;
        for (int i = 0; i < 4; ++i) {
            while (x + addX < 9 && y + addY < 9 && x + addX > 0 && y + addY > 0)
            {
                std::cout << x + addX << " " << y + addY << " ; ";
                c++;
                if(addX > 0)
                {
                    addX++;
                }
                else
                {
                    addX--;
                }
                if(addY > 0)
                {
                    addY++;
                }
                else
                {
                    addY--;
                }
            }
            if(!(x == 1 || x == 8 || y == 1 || y == 8))
            {
                std::cout << std::endl;
            }
            if(i == 0)
            {
                addX = -1;
                addY = 1;
            }
            if(i == 1)
            {
                addX = -1;
                addY = -1;
            }
            if(i == 2)
            {
                addX = 1;
                addY = -1;
            }
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}