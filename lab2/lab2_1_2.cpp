#include <iostream>
using namespace std;

int main()
{
	int a, b; 
	int a1, b1;
	cout << "Enter the coordinates of the rook: ";
	cin >> a >> b;
	cout << "Enter the coordinates of another piece: ";
	cin >> a1 >> b1;
	if (cin.fail() || cin.peek() != 10)
	{
		cout << "incorrect input";
	}
	else if ((a <= 0 || a > 8) || (b <= 0 || b > 8) || (a1 <= 0 || a1 > 8) || (b1 <= 0 || b1 > 8))
	{
		cout << "you went beyond the boundaries";
	}
	else
	{
		if ((a - a1 == 0) || (b - b1 == 0))
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
	}
}
