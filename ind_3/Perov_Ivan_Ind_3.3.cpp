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
		if (cin.fail() or cin.peek() != 10)
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
			int* mas1 = new int[n];
			int* mas2 = new int[n];

			cout << "\nInitial array - ";
			for (int i = 0; i < n; i++)
			{
				rFile >> CurInt;
				cout << CurInt << " ";
				mas1[i] = CurInt; // Копирование элементов из файла
			}
			int swap;
			for (int i = 0; i < n; i++) // Рассчет места чисел в новом массиве и запись
			{
				swap = (i + move) % n;
				if (swap < 0)
				{
					swap = swap + n;
				}
				mas2[swap] = mas1[i];
			}
			cout << "\nNew array moved for " << move << " elements - ";
			for (int i = 0; i < n; i++) // Вывод массива
			{
				cout << mas2[i] << " ";
			}

			delete[] mas1;
			cout << endl << endl;

			char check = ' ';
			rFile.get(check);


			if (check != 10 and !rFile.eof())
			{
				throw INVALID_FILE_INPUT;
			}


		}
		rFile.close();
		cout << "\nFile is fine. End of file. Exit.";
	}
	catch (const char* error) {
		cerr << endl << error << endl;
		return -1;
	}
}