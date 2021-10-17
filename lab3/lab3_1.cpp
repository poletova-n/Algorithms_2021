#include <iostream>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Введите коэффициенты уравнения:";
    double a, b, c, x1, x2;
    std::cin >> a >> b >> c;
    try
    {
        if (!std::cin)
        {
            throw "Ошибка: должно быть число!";
        }
        if (a == 0)
        {
            throw "Ошибка: в квадратном уравнении x^2 не может принимать значение 0";
        }
    }
    catch (const char* error)
    {
        std::cerr << std::endl << error << std::endl;
        return -1;
    }
    double disc = (b * b) - (4 * a * c);
    double sqrtdis = sqrt(disc);
    if (disc < 0)
    {
        std::cout << "корней нет";
    }
    if ((sqrtdis * sqrtdis) == disc && (sqrtdis == int(sqrtdis)))
    {
        if (disc == 0)
        {
            x1 = (-b) / (2 * a);
            std::cout << "один корень: " << x1;
        }
        else
        {
            x1 = (-b + sqrt(disc)) / (2 * a);
            x2 = (-b - sqrt(disc)) / (2 * a);
            std::cout << "первый корень: " << x1 << "\n";
            std::cout << "второй корень: " << x2;
        }
    }
    return 0;
}
