#include <iostream>

using namespace std;

int main()
{
	try
	{
		cout << "enter the coeff-s (numbers!!!)" << endl;

		int a, b, c;
		double d, x1, x2; //коэфф квадр уравн абс, x1,x2 и дискриминант
		cin >> a;
		cin >> b;
		cin >> c; //ввод коэфф

		if (cin.peek() != '\n') //проверяем условия: коэффициенты - числа
		{
			throw "coeff cant be a letter";
		}

		if (a == 0) //если а равно нулю
		{
			throw "A must not equal zero";
		}

		d = b * b - 4 * a * c;
		if (d < 0) //проверяем, не меньше ли дискриминант нуля
		{
			cout << "D < 0. no decisions!" << endl;
		}
		if (d == 0) //проверяем, не равен ли дискр нулю
		{
			x1 = (-b / (2 * a));
			cout << "x1 = " << x1 << endl;
		}
		else
		{
			x1 = (-b + sqrt(d)) / (2 * a); //основное решение кв уравн
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
	}
	catch (const char* error)
	{
		cerr << endl << error << endl;
		return -1;
	}
}