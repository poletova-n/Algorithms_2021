//Квадратное уравнение
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите переменные a b c через пробел: ";

	double a, b, c, x1, x2;

	cin >> a >> b >> c;

	if (cin.fail() || cin.peek() != 10)
	{
		cout << "Вводить можно только числа!";
	}
	else
	{
		cout << "Первая переменная: " << a << endl << "Вторая переменная: " << b << endl << "Третья переменная: " << c << endl;

		int disc = (b * b) - (4 * a * c);

		int sqrtD = sqrt(disc);

		if (disc < 0)
		{
			cout << "Нет корней" << endl;
			return 0;
		}

		if ((sqrtD * sqrtD) == disc)
		{
			if (disc == 0)
			{
				x1 = (-b) / (2 * a);
				cout << "Один корень: " << x1 << endl;
			}
			else
			{
				x1 = (-b + sqrtD) / (2 * a);
				x2 = (-b - sqrtD) / (2 * a);
				cout << "Первый корень: " << x1 << endl;
				cout << "Второй корень: " << x2 << endl;
			}
		}
		else
		{
			cout << "Дискриминант не выводится из под корня!";
		}
	}
}



//Стая ворон
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n = 0;

	cout << "Введите количество ворон: ";
	cin >> n;

	if (cin.good() == false)
	{
		cout << "Вводить можно только числа!";
	}
	else if (n < 0) {
		cout << "Вводить можно только положительные числа!";
	}
	else
	{
		if (n % 10 == 1) {
			cout << "В стае " << n << " ворона";
		}
		else if ((n % 10 >= 5 <= 20)) {
			cout << "В стае " << n << " ворон";
		}
		else
		{
			cout << "В стае " << n << " вороны";
		}
	}
}




//Треугольник
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double a, b, c;

	cout << "Введите стороны треугольника: ";

	cin >> a >> b >> c;

	if (cin.fail() || cin.peek() != 10)
	{
		cout << "Вводить можно только числа!";
	}
	else if (a < 0 || b < 0 || c < 0)
	{
		cout << "Вводить можно только положительный числа!";
	}
	else
	{
		cout << "Сторона а: " << a << endl << "Сторона b: " << b << endl << "Сторона c: " << c << endl;

		if (a == b && a == c && b == c)
		{
			cout << endl << "Треугольник: равностороний";
		}
		else if (a == b && a == c && b == c)
		{
			cout << endl << "Треугольник: равнобедренный";
		}

		else if (pow(c, 2) == pow(a, 2) + pow(b, 2))
		{
			cout << endl << "Треугольник: прямоугольный";
		}
		else
		{
			cout << endl << "Треугольник: разносторонний";
		}
	}
}