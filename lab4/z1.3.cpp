#include <iostream>
int main()
{
    int sum = 0;
    int c = 0;
    int input = 0;
    do{
        std::cin >> input;
        if(input >= 0)
        {
            sum += input;
            c++;
        }
    }while(input != 0);
    c--;
    std::cout << sum * 1.0 / c;
}
