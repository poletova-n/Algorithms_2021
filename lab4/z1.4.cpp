#include <iostream>
int main()
{
    int max = std::numeric_limits<int>::min();
    int maxC = 0;
    int input = 100;
    int c = 0;
    do{
        std::cin >> input;
        c++;
        if(input >= max)
        {
            max = input;
            maxC = c;
        }
    }while(input != 0);
    c--;
    std::cout << max << " " << maxC;
}
