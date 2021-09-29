#include <iostream>

using namespace std;

int main()
{
	cout << "enter 3 whole numbers" << endl;
	int a, b, c, N;
	cin >> a;
	cin >> b;
	cin >> c;
	N = 1;
	if (cin.peek() != '\n')
	{
		cout << "number must be whole" << endl;
	}
	else
	{
		if ((a == b) and (b == c))
		{
			cout << "3" << endl;
		}

		else
		{
			if (a == b)
			{
				N = N + 1;
			}

			if (a == c)
			{
				N = N + 1;
			}

			if (b == c)
			{
				N = N + 1;
			}
			if ((a != b) and (a != c) and (b != c))
			{
				N = 0;
			}

			cout << N << endl;
		}

	}
}