#include <iostream>

bool isMovePossible(int* pos1,int* pos2);

const char* ERROR_INVALID_INPUT = "Error: input must only contain numbers.";

const char* ERROR_IMPOSSIBLE_MOVE = "Error: this move is impossible.";

int main()
{
    try {
        int pos1[] = {0, 0};
        std::cin >> pos1[0] >> pos1[1];
        if (std::cin.fail() || std::cin.peek() != 10)
        {
            throw ERROR_INVALID_INPUT;
        }

        int pos2[] = {0, 0};
        std::cin >> pos2[0] >> pos2[1];
        if (std::cin.fail() || std::cin.peek() != 10)
        {
            throw ERROR_INVALID_INPUT;
        }

        if(!isMovePossible(pos1, pos2))
        {
            throw ERROR_IMPOSSIBLE_MOVE;
        }

        int multX = 0;
        int multY = 0;
        if(pos1[0] - pos2[0] == 0)
        {
            multX = 0;
            if(pos2[1] - pos1[1] > 0)
            {
                multY = 1;
            }
            else
            {
                multY = -1;
            }
        }
        else if(pos1[1] - pos2[1] == 0)
        {
            multY = 0;
            if(pos2[0] - pos1[0] > 0)
            {
                multX = 1;
            }
            else
            {
                multX = -1;
            }
        }

        int x = std::max(abs(pos1[0] - pos2[0]), abs(pos1[1] - pos2[1]));
        for (int i = 0; i <= x; i++)
        {
            std::cout << pos1[0] + multX * i << " " << pos1[1] + multY * i << std::endl;
        }
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }

}

bool isMovePossible(int* pos1,int* pos2)
{
    return pos1[0] - pos2[0] == 0 || pos1[1] - pos2[1] == 0;
}

