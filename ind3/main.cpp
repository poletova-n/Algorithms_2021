#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
const std::string NO_INT = "No Int or Double!";
const std::string NO_OPEN = "No open the File!";

int main()
{
	setlocale(LC_ALL, "rus");
	int SIZE;
	std::ifstream file;

	try
	{
		file.open("test.txt");
		if (!file.is_open())
		{
			throw NO_OPEN;
		}
	}
	catch (const std::string& error)
	{
		std::cerr << "We catch: " << error;
	}


	file >> SIZE;
	int* mas = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		file >> mas[i];
	}


	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mas[i] << " ";
	}


	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if ((mas[i] > mas[j]) and (mas[j] >= 0) and (mas[i] >= 0))
			{
				std::swap(mas[i], mas[j]);
			}
		}

	}

	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mas[i] << " ";
	}

	file.close();
	delete[] mas;









	/*int SIZE;
	std::cin >> SIZE;
	int *mas = new int [SIZE];

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++)
	{
		mas[i] = 0;
	}

	for (int i = 0; i < SIZE; i++)
	{
		mas[i] = rand()%10 - 4;
	}


	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mas[i] << " ";
	}*/

	/*for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if ((mas[i] > mas[j]) and (mas[j] >= 0) and (mas[i] >= 0))
			{
				std::swap(mas[i], mas[j]);
			}
		}

	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mas[i] << " ";
	}*/

	/*delete[] mas;*/













	/*const int SIZE = 5;
	int mas[SIZE]{};

	for (int i = 0; i < SIZE; i++)
	{
		mas[i] = 0;
	}


	try
	{
		for (int i = 0; i < SIZE; i++)
		{
			std::cin >> mas[i];
			if (!std::cin)
			{
				throw NO_INT;
			}
		}
	}
	catch (const std::string& error)
	{
		std::cerr << "We catch: " << NO_INT;
		return -1;
	}

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if ((mas[i] > mas[j]) and (mas[j] >= 0) and (mas[i] >= 0))
			{
				std::swap(mas[i], mas[j]);
			}
		}

	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << mas[i] << " ";
	}*/


	std::cin.clear();
	return 0;
}