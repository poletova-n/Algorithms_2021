#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		int a, b, c;
		std::cout << "Введите координаты слона: ";
		std::cin >> a >> b;
		if (!std::cin)
		{
			throw "Ошибка: Вводить можно только числа";
		}
		if ((a <= 0 || a > 8) || (b <= 0 || b > 8))
		{
			throw "Ошибка: Вы вышли за границы доски";
		}
		std::cout << "Координаты, находящиеся под ударом слона: " << std::endl;
		for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				if ((abs(a - i) == abs(b - j)) && ((a != i) && (b != j)))
				{
				std::cout << "[" << i << " " << j << "]" << std::endl;
				}
			}
		}
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
}