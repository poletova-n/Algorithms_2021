#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		int n;
		std::cout << "Введите число: ";
		std::cin >> n;
		if (!std::cin)
		{
			throw "Ошибка: Вводить можно только числа";
		}
		if (n < 0)
		{
			throw "Ошибка: Вводить можно только положительные числа";
		}
		for (int i = 0; i < n; ++i)
		{
			std::cout << std::endl;
			for (int j = 0; j < i + 1; ++j)
			{
				std::cout << "*";
			}
		}
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
}