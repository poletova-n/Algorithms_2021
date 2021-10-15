#include <iostream>
using namespace std;

int main()
{
	int a, b; // задаем переменные
	int a1, b1;
	cout << "Enter the coordinates of the horse: ";
	cin >> a >> b; // вводим координаты лошади
	cout << "Enter the coordinates of another piece: ";
	cin >> a1 >> b1; // вводим координаты др. фигуры
	if (cin.fail() || cin.peek() != 10) // проверка на корректность ввода
	{
		cout << "incorrect input"; // некорректный ввод
	}
	else if ((a <= 0 || a > 8) || (b <= 0 || b > 8) || (a1 <= 0 || a1 > 8) || (b1 <= 0 || b1 > 8)) // проверка введенных координат
	{
		cout << "you went beyond the boundaries"; // выход за границы доски
	}
	else
	{
		if ((abs(a - a1) == 1 && abs(b - b1) == 2) || (abs(a - a1) == 2 && abs(b - b1) == 1)) // условие при котором ферзь может бить другую фигуру
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
	}
}

