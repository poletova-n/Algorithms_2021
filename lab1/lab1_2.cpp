#include <iostream>
using namespace std;

int main()
{
	int N = 0; // объявляем переменную
	cout << "vvedite chislo: ";
	cin >> N; // вводим число
	if (cin.fail() || N < 0 || cin.peek() != 10) // проверяем корректность ввода
	{
		cout << "kolichestvo zadano nekorektno";
	}
	else
	{
		if (N % 10 == 1 && N % 100 != 11) // если число оканчивается на 1 (кроме 11) - а
		{
			cout << "v stae " << N << " " << "voronA";
		}
		else if ((N % 10 > 1 && N % 10 < 5)) // если число оканчивается на 2, 3 или 4 - ы
		{
			cout << "v stae " << N << " " << "voronY";
		}
		else
		{
			cout << "v stae " << N << " " << "voron"; // остальные случаи - нулевое окончание 
		}
	}
}
