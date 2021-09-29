#include <iostream>

using namespace std;

int main()
{
	cout << "enter 3 whole numbers" << endl;
	int a, b, c, d;
	d = -32768;
	cin >> a;
	cin >> b;
	cin >> c;
	if (cin.peek() != '\n')
	{
		cout << "number must be whole" << endl;
	}
	else
	{
		if (a >= d)
		{
			d = a;
		}
		if (b >= d)
		{
			d = b;
		}
		if (c >= d)
		{
			d = c;
		}
		cout << "max is " << d;
	}
}