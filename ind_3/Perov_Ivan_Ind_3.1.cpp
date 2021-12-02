#include <iostream>
using namespace std;
const char* INVALID_INPUT = "Error - Invalid input";
//Статический сдвиг
int main() {
	try {
		int move;
		cout << "Move for - ";
		cin >> move;
		if (cin.fail() || cin.peek() != 10 || move < 1)
		{
			throw INVALID_INPUT;
			return -1;
		}

		int mas1[] = { 12,1112,546,456,12,21,1,1,85 }; // Наполнение первоначального массива
		int lenMas1 = (sizeof(mas1) / sizeof(*mas1));

		cout << "Initial array - ";
		for (int i = 0; i < lenMas1; i++) // Вывод первоначального массива
		{
			cout << mas1[i] << " ";
		}

		int* mas2 = new int[lenMas1 + move];
		for (int i = 0; i < move; i++) // Наполнение нулями
		{
			mas2[i] = 0;
		}
		for (int i = 0; i < lenMas1; i++) // Копирование элементов из первого массива
		{
			mas2[i + move] = mas1[i];
		}

		cout << "\nNew array moved for " << move << " elements - ";
		for (int i = 0; i < lenMas1 + move; i++) // Вывод итогового массива
		{
			cout << mas2[i] << " ";
		}
		delete[] mas2;
	}
	catch (const char* error)
	{
		cerr << error << endl;
	}
}