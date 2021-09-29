#include <iostream>

using namespace std;

int main()
{
	cout << "enter 3 whole numbers" << endl;
	int a, b, c, min, max, mid;
	min = 32768;
	max = -32768;
	mid = -32768;
	cin >> a;
	cin >> b;
	cin >> c;
	if (cin.peek() != '\n')
	{
		cout << "number must be whole" << endl;
	}
	else
	{
		if (a <= min)
		{
			min = a;
		}
		if (b <= min)
		{
			min = b;
		}
		if (c <= min)
		{
			min = c;
		}

		if (a >= max)
		{
			max = a;
		}
		if (b >= max)
		{
			max = b;
		}
		if (c >= max)
		{
			max = c;
		}
		if ((a == max) and (b == min))
		{
			mid = c;
		}
		if ((a == max) and (b == min))
		{
			mid = c;
		}
		if ((a == max) and (c == min))
		{
			mid = b;
		}
		if ((b == max) and (c == min))
		{
			mid = a;
		}
		if ((b == max) and (a == min))
		{
			mid = c;
		}
		if ((c == max) and (b == min))
		{
			mid = a;
		}
		if ((c == max) and (a == min))
		{
			mid = b;
		}
		cout << min << " " << mid << " " << max;
	}
}