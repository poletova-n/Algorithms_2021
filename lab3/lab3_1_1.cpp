#include <iostream>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int year = 0;
    int visokosniy = 1;
    int nevisokosniy = 0;
	std::cout << "Enter year: ";
	std::cin >> year;
	try
	{
		if (!std::cin)
		{
			throw "Ошибка: год должен быть числом!";
		}
	}
	catch (const char* error)
	{
		std::cerr << std::endl << error << std::endl;
		return -1;
	}
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
	{
		std::cout << visokosniy << "\n" << "this is a leap year";
	}
	else
	{
		std::cout << nevisokosniy << "\n" << "this is not a leap year";
	}
}

