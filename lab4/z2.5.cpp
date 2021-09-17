#include <iostream>

void drawTr(int i, int n);

void drawFigure(int n);

const char* ERROR_INVALID_INPUT = "Error: input must only contain positive integers.";

int main()
{
    try
    {
        std::cout << "Input size of side:";
        int n = 0;
        std::cin >> n;
        if (std::cin.fail() || std::cin.peek() != 10 || n < 0)
        {
            throw ERROR_INVALID_INPUT;
        }
        drawFigure(n);
    }
    catch(const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
}


void drawFigure(int n)
{
    for (int i = 0; i < n + 1; ++i)
    {
        drawTr(i, n);
    }
    for (int i = n - 1; i > 0; --i)
    {
        drawTr(i, n);
    }
}

void drawTr(int i, int n)
{
    for (int j = 0; j < n - i; ++j)
    {
        std::cout << " ";
    }
    for (int j = 0; j < i; ++j)
    {
        std::cout << "*";
    }
    for (int j = 0; j < i - 1; ++j)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
}