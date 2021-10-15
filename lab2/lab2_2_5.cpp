#include <iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cout << "enter the coordinates first edge: ";
	cin >> x1 >> y1;
	cout << "enter the coordinates the second edge: ";
	cin >> x2 >> y2;

	if (cin.fail() || cin.peek() != 10)
	{
		cout << "incorrect input";
	}
	else if (x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0)
	{
		cout << "vse coordinaty otlichny ot nulya";
	}
	else
	{
		if ((x1 > 0 && y1 > 0) && (x2 > 0 && y2 > 0))
		{
			cout << "both of edge in first quarter";
		}
		else if ((x1 < 0 && y1 > 0) && (x2 < 0 && y2 > 0))
		{
			cout << "both of edge in second quarter";
		}
		else if ((x1 < 0 && y1 < 0) && (x2 < 0 && y2 < 0))
		{
			cout << "both of edge in third quarter";
		}
		else if ((x1 > 0 && y1 < 0) && (x2 > 0 && y2 < 0))
		{
			cout << "both of edge in fourth quarter";
		}
		else
		{
			cout << "both of edge in different sides";
		}
	}
}