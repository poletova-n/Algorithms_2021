#include <iostream>
using namespace std;
const char* INVALID_INPUT = "Error - Invalid input";
//Статический сдвиг
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

		int mas1[] = { 1,2,3,4,5 }; // Наполнение первоначального массива
		int lenMas1 = (sizeof(mas1) / sizeof(*mas1));

		cout << "Initial array - ";
		for (int i = 0; i < lenMas1; i++) // Вывод первоначального массива
		{
			cout << mas1[i] << " ";
		}

		int* mas2 = new int[lenMas1];
		int swap;

		for (int i = 0; i < lenMas1; i++) // Рассчет места чисел в новом массиве и запись
		{
			swap = (i + move) % lenMas1;
			if (swap < 0)
			{
				swap = swap + lenMas1;
			}
			mas2[swap] = mas1[i];
		}

		cout << "\nNew array moved for " << move << " elements - ";
		for (int i = 0; i < lenMas1; i++) // Вывод итогового массива
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