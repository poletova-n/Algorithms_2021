#include <iostream>
#include <fstream>
#include <stdlib.h>

const char* ERROR_FILE_NOT_OPEN = "The file was not open!\n";
const char* ERROR_INVALID_INPUT = "Either a non-integer  number was entered, or a non-number was entered, end of the program!\n";
const int Columns = 5, Lines = 4;
int CheckColumns(int Mass[][Columns], int const lines);
int FindMinSum(int** Mass, int line, int columns);
int** inputArray(std::ifstream& input, int** Mass, int line, int columns);

int main()
{
	int Const_A[Lines][Columns] = { { 1, 2, 5, 4, 2 }, { 7, 8, 4, 5, 1 }, { 9, 9, 2, 6, 2 }, { 10, 3, 6, 7, 9 } };
	std::cout << "Const Array: \n";
	for (int i = 0; i < Lines; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			std::cout << Const_A[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "The number of columns whose elements are ordered in ascending order of elements is: " << CheckColumns(Const_A, Lines) << "\n";

	std::ifstream input("C:/Users/PetrK/Documents/Visual Studio Files/ConsoleApplication16/input.txt");
	std::ofstream output("C:/Users/PetrK/Documents/Visual Studio Files/ConsoleApplication16/output.txt");
	int line = 0, columns = 0;
	try
	{
		if (!input.is_open())
		{
			throw ERROR_FILE_NOT_OPEN;
		}

		input >> line >> columns;

		if ((!input) or input.fail())
		{
			throw ERROR_INVALID_INPUT;
		}
	}
	catch (const char* error)
	{
		std::cerr << "\n" << error;
		return -1;
	}

	int** array = new int* [line];
	for (int i = 0; i < line; i++)
	{
		array[i] = new int[columns];
	}

	output << "The minimum among the sums of the elements of the diagonals parallel to the main diagonal of the matrix: " << FindMinSum(inputArray(input, array, line, columns), line, columns);
	input.close();
	output.close();
	return 0;

}

int CheckColumns(int Mass[][Columns], int const lines)
{
	int count = 0;
	bool flag = 0;
	for (int j = 0; j < Columns; j++)
	{
		flag = 0;
		for (int i = 0; i < lines - 1; i++)
		{

			if (Mass[i][j] >= Mass[i + 1][j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			count++;
		}
	}
	return count;
}


int** inputArray(std::ifstream& input, int** Mass, int line, int columns)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			input >> Mass[i][j];
		}
	}
	return Mass;
}
int FindMinSum(int** Mass, int line, int columns)
{

	int k = 0, sum = 0, k1 = 1, SumMin1 = INT_MAX, SumMin2 = INT_MAX;
	for (int k = 1; k < columns; k++)
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if ((i + k == j) and (i + k < columns))
				{
					if (k == k1)
					{
						sum = sum + Mass[i][j];
					}
					else
					{
						SumMin1 = std::min(sum, SumMin1);
						sum = Mass[i][j];
						k1 = k;
					}
					if (k == columns - 1)
					{
						SumMin1 = std::min(sum, SumMin1);
						sum = Mass[i][j];
						SumMin1 = std::min(sum, SumMin1);
						k1 = k;
					}

				}
			}
		}

	}
	int h1 = 1;
	sum = 0;
	for (int h = 1; h < line; h++)
	{
		for (int j = 0; j < columns; j++)
		{
			for (int i = 0; i < line; i++)
			{
				if ((j + h == i) and (j + h < line))
				{
					if (h == h1)
					{
						sum = sum + Mass[i][j];
					}
					else
					{
						SumMin2 = std::min(sum, SumMin2);
						sum = Mass[i][j];
						h1 = h;
					}
					if (h == line - 1)
					{
						SumMin2 = std::min(sum, SumMin2);
						sum = Mass[i][j];
						SumMin2 = std::min(sum, SumMin2);
						h1 = h;
					}

				}
			}
		}

	}
	return std::min(SumMin1, SumMin2);
}