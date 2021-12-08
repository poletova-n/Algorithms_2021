#include <iostream>
#include <fstream>
using namespace std;
const char* INVALID_INPUT = "Error - Invalid input";
const char* FILE_NOT_FOUND = "Error - File not found";

void fillWithNumbers(int**& matrix, int mSize) {
	int splash;
	splash = mSize / 2;

	for (int i = 0; i < mSize; i++) // 1 - n / n - 1
	{
		if (i < splash) 
		{
			for (int j = 0; j < mSize; j++)
			{
				matrix[i][j] = i + 1;
			}
		}
		else
		{
			for (int j = 0; j < mSize; j++)
			{
				matrix[i][j] = mSize -  i;
			}
		}
	}

	for (int i = 0; i < splash; i++) 
	{
		for (int j = i; j < mSize-i; j++)
		{
			matrix[j][i] = i + 1;
			//cout << i << " " << j << '\t';
		}
	}
	int count;
	if (mSize % 2 == 0)
	{
		count = 0;
	}
	else 
	{
		count = -1;
	}

	
	/*cout << splash << " - splash \t" << mSize << " - mSize" << endl;*/
	for (int i = splash; i < mSize; i++)
	{
		for (int j = mSize-i-1; j <= i; j++)
		{
			matrix[j][i] = splash - count;
			/*cout << i << " " << j << '\t';*/
		}
		count++;
	}
	
	ofstream wFile;
	wFile.open("C:\\ans1.txt");
	if (!wFile.is_open())
	{
		throw FILE_NOT_FOUND;
	}



	for (int i = 0; i < mSize; i++)
	{

		for (int j = 0; j < mSize; j++)
		{
			wFile << matrix[i][j] << " ";
		}
		wFile << endl;
	}
}

int main() {
	try 
	{
		setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);
		int mSize;
		cout << "¬ведите размерность матрицы - ";
		cin >> mSize;
		if (cin.fail() or cin.peek() != 10)
		{
			throw INVALID_INPUT;
			return -1;
		}
		int** matrix = new int* [mSize];
		for (int i = 0; i < mSize; i++)
		{
			matrix[i] = new int[mSize];
			for (int j = 0; j < mSize; j++)
			{
				matrix[i][j] = 0;
			}
			std::cout << "\n";
		}
		cout << endl;
		fillWithNumbers(matrix, mSize);

		for (int i = 0; i < mSize; i++)
			delete[] matrix[i];
		delete[] matrix;
		cout << "\nAnswer in file ans1. Exit.";
		return 0;
	}

	catch (const char* error)
	{
		cerr << error << endl;
	}
}
