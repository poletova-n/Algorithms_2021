#include <iostream>

int main()
{
    int a, b, c, count = 0;
    std::cout << "Enter three numbers" << std:: endl;
    std::cin >> a >> b >> c;
    if ((a == b) && (a == c))
    {
        std::cout << "3 identical numbers";
    }
    else if ((a != c) && (a != b) && (b != c))
    {
        std::cout << "0 identical numbers";
    }
    else
    {
        std::cout << "2 identical numbers";
    }
}