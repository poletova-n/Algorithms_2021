#include <iostream>
#include <fstream>

const char* NO_CREATE = "Столбцы и строки матрицы не имеют равной длины!";
const int ROWS = 3;
const int COLLONS = 5;

void maxSumMas(int** arr, int ROWS, int COLLONS);
void reverseMas(int** arr, const int ROWS, const int COLLONS);
int checkMas(int mas[][ROWS], int COLLONS);


int main()
{
	setlocale(LC_ALL, "Russian");
	int rows = 3;
	int collons = 5;
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[collons];
	}

	try
	{
		reverseMas(arr, rows, collons);
		maxSumMas(arr, rows, collons);
	}
	catch (const char* error)
	{
		std::cerr << "Найдена ошибка: " << error;
	}



	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;




	int mas[COLLONS][ROWS]{ { 1,2,3 }, { 2,1,0 }, { 4,4,4 }, { 1,3,6 }, {1,3,2} };

	for (int i = 0; i < COLLONS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			std::cout << mas[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << checkMas(mas, COLLONS);


}

void maxSumMas(int** mas, int rows, int collons) {

	std::ofstream file;
	file.open("test.txt");

	int maxSum = std::numeric_limits<int>::min();
	if (rows == collons)
	{
		//1
		int copyColons = collons;
		for (int y = 0; y < rows; ++y)
		{
			int index = y;
			int curSum = 0;
			for (int x = 0; x < copyColons; ++x)
			{
				if ((x == copyColons) or (index == rows)) break;
				std::cout << "matrix[" << index << "]" << "[" << x << "]  ";
				curSum += mas[index++][x];
				if (curSum > maxSum) {
					maxSum = curSum;
				}
			}
			copyColons--;
			std::cout << std::endl;
		}
		std::cout << std::endl;


		//2
		int copyRows = rows;
		for (int y = 0; y < collons; ++y)
		{
			int index = y;
			int curSum = 0;
			for (int x = 0; x < copyRows; ++x)
			{
				if ((x == copyRows) or (index == collons)) break;
				std::cout << "matrix[" << x << "]" << "[" << index << "]  ";
				curSum += mas[x][index++];
				if (curSum > maxSum)
				{
					maxSum = curSum;
				}
			}
			std::cout << std::endl;
			copyRows--;
		}
		std::cout << std::endl;


		//3
		for (int y = 0; y < collons; ++y)
		{
			int curSum = 0;
			int indexRows = y;
			for (int x = 0; x <= y; ++x)
			{
				if (indexRows == rows) break;
				std::cout << "matrix[" << x << "]" << "[" << indexRows << "]  ";
				curSum += mas[x][indexRows--];
				if (curSum > maxSum)
				{
					maxSum = curSum;
				}
			}
			std::cout << std::endl;

		}
		std::cout << std::endl;


		//4
		for (int y = 0; y < collons; ++y)
		{
			int index = y;
			int curSum = 0;
			for (int x = ROWS - 1; x >= 0; --x)
			{
				if (index == collons) break;
				std::cout << "matrix[" << index << "]" << "[" << x << "]  ";
				curSum += mas[index++][x];
				if (curSum > maxSum)
				{
					maxSum = curSum;
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	else throw NO_CREATE;
	std::cout << std::endl;
	std::cout << maxSum;

	file << maxSum;
	file.close();

	std::cout << std::endl;
}

void reverseMas(int** arr, int ROWS, int COLLONS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLLONS; j++)
		{
			arr[i][j] = rand() % 10;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int checkMas(int mas[][ROWS], int COLLONS)
{
	int cntStr = 0;
	for (int i = 0; i < COLLONS; ++i)
	{
		int checkOut = 0;
		for (int j = 0; j < ROWS - 1; ++j)
		{
			if (mas[i][j] >= mas[i][j + 1])
			{
				checkOut = 1;
			}
		}
		if (checkOut == 0) cntStr++;
	}
	return cntStr;
}