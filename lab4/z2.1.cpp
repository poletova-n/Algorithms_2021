#include <iostream>

int main()
{
    int pos1[] = {0,0};
    int pos2[] = {0,0};
    int multX = 0;
    int multY = 0;
    std::cin >> pos1[0] >> pos1[1];
    std::cin >> pos2[0] >> pos2[1];
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
    for (int i = 0; i <= x  ; i++)
    {
        std::cout << pos1[0] + multX * i << " " << pos1[1] + multY * i << std::endl;
    }
}
