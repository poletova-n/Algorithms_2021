#include <iostream>
using namespace std;

int main()
{
	int mas[3];
	cout << "enter numbers: ";
	cin >> mas[0] >> mas[1] >> mas[2];
	int count = 0;

	if (cin.fail() || cin.peek() != 10) // проверка на корректный ввод чисел
	{
		cout << "incorrect input";
	}

	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (mas[i] == mas[j])
				{
					count += 1;
				}
			}
		}
		cout << "Sovpadenij: " << count;
	}
	return 0;
}

