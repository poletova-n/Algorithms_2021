#include <iostream>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		int n = 0;
		int count = 0;
		int max = 0;
		int nomer = 0;
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
			count++;
			if (n >= max)
			{
				max = n;
				nomer = count;
			}
		}
		std::cout << "Максимальное значение: " << max << std::endl << "Его номер: " << nomer;
		return 0;
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
}