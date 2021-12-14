#include <iostream>
#include <fstream>
using namespace std;
const char* INVALID_INPUT = "Error - Invalid input";
const char* FILE_NOT_FOUND = "Error - File not found";

void fillWithNumbers(char**& matrix, int mSize) {
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	int counter=0;
	for (int i = 0; i < mSize; i++)
	{
		for (int j = 0; j < mSize; j++)
		{
			for (int g = 0; g < j; g++)
			{
				if (matrix[i][j] == matrix[i][g])
				{
					counter++;
					j = mSize;
				}
			}
		}
	}
	cout << "Совпадения в " << counter << " строках.";
}

int main() {
	try
	{
		setlocale(LC_ALL, "Russian"); //#include <windows.h> SetConsoleOutputCP(CP_UTF8);
		char alph[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		int mSize;
		cout << "Введите размерность матрицы - ";
		cin >> mSize;
		if (cin.fail() or cin.peek() != 10)
		{
			throw INVALID_INPUT;
			return -1;
		}
		char** matrix = new char* [mSize];
		for (int i = 0; i < mSize; i++)
		{
			matrix[i] = new char[mSize];
			for (int j = 0; j < mSize; j++)
			{
				matrix[i][j] = alph[rand() % 26];
			}
		}
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


