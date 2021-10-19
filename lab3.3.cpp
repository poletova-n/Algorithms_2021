#include <iostream>
using namespace std;
const string ERROR_NOT_NUMBER = "error! enter the whole number.";

const string ERROR_NOT_POSITIVE_NUMBER = "no such triangle exists. numbers must be positive.";

const string ERROR_NOT_TRIANGLE = "no such triangle exists. c>a+b or c=a+b.";
int main()
{
	try
	{
		cout << "enter the POSITIVE lengths of the sides of the triangle in ascending order \n";
		double a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		if (cin.fail() || cin.peek() != 10) {
			throw ERROR_NOT_NUMBER;
		}
		if ((a < 0) || (a == 0) || (b < 0) || (b == 0) || (c < 0) || (c == 0))
		{
			throw ERROR_NOT_POSITIVE_NUMBER;
		}
		if (c >= (a + b))
		{
			throw ERROR_NOT_TRIANGLE;
		}
		else {
			if (c * c == (a * a + b * b)) // проверяем теорему пифагора
				cout << "rectangular triangle\n";
			else
				if ((a == b) and (b == c)) // проверяем равенство трех сторон
				{
					cout << "equilateral triangle\n";
				}
				else
				{
					if (c * c > (a * a + b * b))// проверяем на свойство остроугольного треуг
					{
						cout << "acute-angled triangle\n";
					}
					else
					{
						cout << "obtuse triangle\n";
					}
					if ((a == c) || (b == c) || (a == b)) // проверяем равенство двух сторон
					{
						cout << "isosceles triangle\n";
					}
				}
		}
	}
	catch (const string& error) {
		cerr << endl << error << endl;
		return -1;
	}
}
