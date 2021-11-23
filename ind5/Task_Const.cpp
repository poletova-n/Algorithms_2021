#include <iostream>
#include <stdlib.h>


const char* ERROR_INVALID_INPUT = "The array contains a number out of the range of an integer type! \n";
const int Columns = 5, Lines = 4;
int CheckColumns(long long Mass[][Columns], int const lines);


int main()
{
	long long Const_A[Lines][Columns] = { { 1, 2, 5, 4, 2 }, { 7, 8, 4, 5, 1 }, { 9, 9, 2, 6, 2 }, { 10, 3, 6, 7, 9 } };

	std::cout << "Const Array: \n";
	try
	{

		for (int i = 0; i < Lines; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if ((Const_A[i][j] > INT_MAX) or (INT_MIN > Const_A[i][j]))
				{
					throw ERROR_INVALID_INPUT;
				}
				std::cout << Const_A[i][j] << " ";
			}
			std::cout << std::endl;
		}


	}
	catch (const char* error)
	{
		std::cerr << "\n" << error;
		return -1;
	}
	std::cout << "The number of columns whose elements are ordered in ascending order of elements is: " << CheckColumns(Const_A, Lines) << "\n";

	return 0;

}

int CheckColumns(long long Mass[][Columns], int const lines)
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
