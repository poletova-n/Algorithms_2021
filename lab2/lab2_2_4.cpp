#include <iostream>
using namespace std;

int main()
{
	int mas[3] = { 0,0,0 };
	cout << "enter numbers: ";
	cin >> mas[0] >> mas[1] >> mas[2];

	bool a = false, b = false;

	if (cin.fail() || cin.peek() != 10) 
	{
		cout << "incorrect input";
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			if (mas[i] % 2 == 0)
			{
				a = true;
			}
			else
			{
				b = true;
			}
		}
		if (a && b)
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
	}
}