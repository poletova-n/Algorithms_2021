#include <iostream>
#include <iomanip>
using namespace std;

const string NO_INT = "It is not integer or double!";

void IntProof(double x)
{
	if (cin.fail() or cin.peek() != 10)
	{
		throw NO_INT;
	}
	return;
}
int main()
{
	int cal = 0;
	int count = 0;
	double max1 = numeric_limits <double> ::min();

	cout << "Vvodite chicla: " << endl;

	try
	{
		while (true)
		{
			cout << setw(2);
			cin >> count;
			IntProof(count);
			if (count == 0) break;
			if (count >= max1)
			{
				max1 = count;
				cal = 0;
			}
			else
			{
				cal++;
			}
		}
	}
	catch (const string& error)
	{
		cerr << "Slovlena oshibka! " << setw(30) << error;
		return -1;
	}

	cout << "Kolichestvo chisel posle maximalnogo chisla: " << cal;

	cin.clear();
	return 0;
}