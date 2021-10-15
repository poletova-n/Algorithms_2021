#include <iostream>
#include <stdlib.h>
using namespace std;

int usp(const void* a, const void* b) // функция сравнения элементов массива
{
	return (*(int*)a - *(int*)b); //проверка результата вычитания 
}
int main()
{
	int mas[3]; // задаем количество чисел в массиве
	cout << "enter numbers: ";
	cin >> mas[0] >> mas[1] >> mas[2];
	int i; // счетчик
	if (cin.fail() || cin.peek() != 10) // проверка на корректный ввод чисел
	{
		cout << "incorrect input";
	}
	else
	{
		qsort(mas, 3, sizeof(int), usp); // сортируем массив
		for (i = 0; i < 3; i++)
		{
			cout << mas[i] << " ";
		}
		cout << "\n";
	}
	system("pause");
}