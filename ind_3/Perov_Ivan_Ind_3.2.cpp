#include <iostream>
using namespace std;
const char* INVALID_INPUT = "Error - Invalid input";
//Динамический сдвиг
int main() {
	try
	{
		int lenDMas1;
		cout << "Array size - ";
		cin >> lenDMas1;
		if (cin.fail() or cin.peek() != 10 or lenDMas1 < 1)
		{
			throw INVALID_INPUT;
			return -1;
		}

		int move;
		cout << "Move for - ";
		cin >> move;
		if (cin.fail() or cin.peek() != 10 or move < 1)
		{
			throw INVALID_INPUT;
			return -1;
		}

		int* DMas1 = new int[lenDMas1];
		int* DMas2 = new int[lenDMas1 + move];

		for (int i = 0; i < lenDMas1; i++) // Наполнение первоначального массива
		{
			DMas1[i] = rand() % 100;
		}
		cout << "Initial array - ";
		for (int i = 0; i < lenDMas1; i++) // Вывод первоначального массива
		{
			cout << DMas1[i] << " ";
		}

		cout << endl;
		for (int i = 0; i < move; i++) // Наполнение нулями 
		{
			DMas2[i] = 0;
		}
		for (int i = 0; i < lenDMas1; i++) // Копирование элементов из первого массива
		{
			DMas2[i + move] = DMas1[i];
		}
		cout << "New array moved for " << move <<" elements - ";
		for (int i = 0; i < lenDMas1 + move; i++) // Вывод итогового массива
		{
			cout << DMas2[i] << " ";
		}
		delete[] DMas1;
		delete[] DMas2;
	}
	catch (const char* error){
		cerr << error << endl;
	}
}