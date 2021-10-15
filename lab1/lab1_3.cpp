#include <iostream>
using namespace std;

int main()
{
	double a, b, c; // вводим числовые значения для сторон
	cout << "vvedite storony treugolnika: ";
	cin >> a >> b >> c; // вводим значения
	double sigCosA = b * b + c * c - a * a;
	double sigCosB = c * c + a * a - b * b;
	double sigCosC = a * a + b * b - c * c;
	if ((cin.fail() || cin.peek() != 10) || (a < 0 || b < 0 || c < 0)) //проверяем корректность введенных чисел
	{
		cout << "nekorrektniy vvod dannyh";
	}
	else if (a >= b + c || b >= c + a || c >= a + b)
	{
		cout << "takogo treugolnika net";
	}
	else
	{
		if (a == b && a == c && b == c)
		{
			cout << "treugolnik ravnostoronniy" << endl;
		}
		else if (a == b || a == c || b == c)
		{
			cout << "treugolnik ravnobedrenniy" << endl;
		}
		if (sigCosA == 0 || sigCosB == 0 || sigCosC == 0)
		{
			cout << "treugolnik pryamoy" << endl;
		}
		else if (sigCosA < 0 || sigCosB < 0 || sigCosC < 0)
		{
			cout << "treugolnik tupoy" << endl;
		}
		else
		{
			cout << "treugolnik osrtiy" << endl;
		}
	}
}