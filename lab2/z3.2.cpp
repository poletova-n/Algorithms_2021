#include <iostream>
#include <iomanip>

int main()
{
    float a = 1.0f;
    int b = 1;
    while ((int)a == b)
    {
        b++;
        a = b;
    }
    std::cout << "Error can be caught since: " << b << " (float "<< std::fixed << std::setprecision(0) << a << ")";
}