#include <iostream>
int main()
{
    int min = std::numeric_limits<int>::max();
    int minC = 0;
    int input = 100;
    int c = 0;
    do{
        std::cin >> input;
        c++;
        if(input <= min && input > 0)
        {
            min = input;
            minC = c;
        }
    }while(input != 0);
    c--;
    std::cout << min << " " << minC;
}
