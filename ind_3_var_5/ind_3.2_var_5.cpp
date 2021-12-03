#include <iostream>
using namespace std;
const char* error= "enter correct number";
int main()
{
	srand((unsigned)time(NULL));
	int n=0;
	cout << "enter the number" << endl;
	cin >> n;
	if (cin.fail() || cin.peek() != '\n' || n < 1)
	{
		cerr << error << endl;
		return -1;
	}
	int* array = new int[n];
	int max = numeric_limits<int>::min();
	

	for (int i = 0; i < n; i++)
	{
		array[i] = rand();
		if (array[i] % 2 == 0)
		{
			cout << array[i] << endl;
		}

	}
	for (int j = 0; j < n; j++)
	{

		if (array[j] % 2 == 1)
		{
			cout << array[j] << endl;
		}

	}
}

