#include <iostream>
using namespace std;

int main()
{
	int a, b, c; // объявляем переменные
	cout << "Enter three numbers: ";
	cin >> a >> b >> c; // вводим три числа
	if (cin.fail() || cin.peek() != 10)  //проверка что введенные данные являются числами
	{
		cout << "icorrect input";
	}
	else if (a >= 0 && b >= 0 && c >= 0) // условия для положительных целых чисел:
	{
		if ((a >= b) && (a >= c))
		{
			cout << "largest number: " << a;
		}
		else if ((b >= a) && (b >= c))
		{
			cout << "largest number: " << b;
		}
		else
		{
			cout << "largest number: " << c;
		}
	}
	else // условия для отрицательных целых чисел:
	{
		if ((abs(a) <= abs(b)) && (abs(a) <= abs(c)))
		{
			cout << "largest number: " << a;
		}
		else if ((abs(b) <= abs(a)) && (abs(b) <= abs(c)))
		{
			cout << "largest number: " << b;
		}
		else
		{
			cout << "largest number: " << c;
		}
	}
}
