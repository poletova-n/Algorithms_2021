﻿#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		double n = 0;
		double count = 0;
		double sum = 0;
		double sredn = 0;
		while (true)
		{
			std::cout << "Введите числа: ";
			std::cin >> n;
			if (!std::cin)
			{
				throw "Ошибка: вводить можно только числа";
			}
			if (n == 0)
			{
				break;
			}
			sum += n;
			count++;
			sredn = sum / count;
		}
		std::cout << "Среднее арифметическое: " << sredn << std::endl;
		return 0;
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
}