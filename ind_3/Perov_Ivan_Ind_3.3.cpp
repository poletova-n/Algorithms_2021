#include <iostream>
#include <fstream>
using namespace std;
const char* FILE_NOT_FOUND = "Error - File not found";
const char* INVALID_INPUT = "Error - Invalid input";
const char* INVALID_FILE_INPUT = "Error - Invalid file input";
//Сдвиги из файла
int main() {
	try {
		int move;
		cout << "Move for - ";
		cin >> move;
		if (cin.fail() or cin.peek() != 10 or move < 1)
		{
			throw INVALID_INPUT;
			return -1;
		}

		ifstream rFile("C:\file.txt");
		rFile.open("C:\\file.txt");
		if (!rFile.is_open())
		{
			throw FILE_NOT_FOUND;
		}

		while (!rFile.eof())
		{
			int n = 0;
			int CurInt = 0;
			rFile >> n;
			int* mas = new int[n + move];


			for (int i = 0; i < move; i++) // Наполнение нулями
			{
				mas[i] = 0;
			}

			cout << "\nInitial array - ";
			for (int i = 0; i < n; i++)
			{
				rFile >> CurInt;
				cout << CurInt << " ";
				mas[i + move] = CurInt; // Копирование элементов из файла
			}

			cout << "\nNew array moved for " << move << " elements - ";
			for (int i = 0; i < n + move; i++) // Вывод массива
			{
				cout << mas[i] << " ";
			}

			delete[] mas;
			cout << endl << endl;

			char check = ' ';
			rFile.get(check);


			if (check != 10 and !rFile.eof())
			{
				throw INVALID_FILE_INPUT;
			}


		}
		rFile.close();
	}
	catch (const char* error) {
		cerr << error << endl;
		return -1;
	}
}