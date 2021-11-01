#include <iostream>
#include <fstream>
#include <algorithm>

void reverceWord(char* wordP, char* wordQ, char* wordPQ);

const char WORD_OVERFLOW[] = "Превышен лимит вводимых значений!";
const char NO_OPEN[] = "Файл не открывается!";
const char NO_PLUS[] = "Размер массива должен быть положительным!";
const char NO_INTEGER[] = "Размер массива указан не целочисленным значением!";

int main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		std::ifstream fileTake;
		fileTake.open("test4.txt");

		std::ofstream fileEnter;
		fileEnter.open("test4.txt", std::ofstream::app);

		int sizeP = 0;
		int sizeQ = 0;


		if (!fileTake.is_open())
		{
			throw NO_OPEN;
		}
		else {

			fileTake >> sizeP;
			if (sizeP < 0) throw NO_PLUS;
			char* wordP = new char[sizeP];
			for (int i = 0; i < sizeP; i++)
			{
				fileTake >> wordP[i];
			}


			fileTake >> sizeQ;
			if (sizeQ < 0) throw NO_PLUS;
			char* wordQ = new char[sizeQ];
			for (int i = 0; i < sizeQ; i++)
			{
				fileTake >> wordQ[i];
			}

			int sumSize = sizeP + sizeQ;
			char* wordPQ = new char[sumSize];
			reverceWord(wordP, wordQ, wordPQ);


			fileEnter << "Результат: ";
			for (int i = 0; i < sumSize; i++)
			{
				fileEnter << wordPQ[i];
			}

			delete[] wordP;
			delete[] wordQ;
			delete[] wordPQ;
			fileTake.close();
			fileEnter.close();
		}
	}
	catch (const char* errorOverflow)
	{
		std::cerr << "Найдена ошибка: " << errorOverflow;
		return -1;
	}




	std::cin.clear();
	std::cin.ignore(90000, '\n');
	return 0;
}

void reverceWord(char* wordP, char* wordQ, char* wordPQ)
{
	int sizeP = strlen(wordP);
	int sizeQ = strlen(wordQ);
	int sumSize = sizeP + sizeQ;
	int pos = 0;
	int iterator = 0;

	while (iterator < sumSize)
	{
		if (iterator < sizeP)
		{
			wordPQ[pos] = wordP[iterator];
			pos++;
		}

		if (iterator < sizeQ)
		{
			wordPQ[pos] = wordQ[iterator];
			pos++;
		}
		iterator++;
	}
}
