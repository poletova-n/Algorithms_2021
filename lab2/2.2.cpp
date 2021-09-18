#include <iostream>

int main()
{
    int a, b, c, x1, x2, x3;
    std::cout << "Enter three numbers" << std::endl;
    std::cin >> a >> b >> c;
    if (a < b && a < c)
    {
        x1 = a;
        if (b < c)
        {
            x2 = b;
            x3 = c;
        }
        else
        {
            x2 = c;
            x3 = b;
        }
    }
    if (b < a && b < c)
    {
        x1 = b;
        if (a < c)
        {
            x2 = a;
            x3 = c;
        }
        else
        {
            x2 = c;
            x3 = a;
        }
    }
    if (c < b && c < a)
    {
        x1 = c;
        if (b < a)
        {
            x2 = b;
            x3 = a;
        }
        else
        {
            x2 = a;
            x3 = b;
        }
    }
    std::cout << x1 << " " << x2 << " " << x3;
}