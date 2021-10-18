#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		int a, b;
		int a1, b1;
		std::cout << "Введите координаты ферзя: ";
		std::cin >> a >> b;
		std::cout << "Введите координаты фигуры: ";
		std::cin >> a1 >> b1;
		if (!std::cin)
		{
			throw "Ошибка: должно быть задано число!";
		}
		if ((a <= 0 || a > 8) || (b <= 0 || b > 8) || (a1 <= 0 || a1 > 8) || (b1 <= 0 || b1 > 8))
		{
			throw "Вы вышли за границы";
		}
		if (abs(a - a1) == abs(b - b1) || (a - a1 == 0) || (b - b1 == 0))
		{
			std::cout << "Да";
		}
		else
		{
			std::cout << "Нет";
		}
		return 0;
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
}