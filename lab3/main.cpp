#include <iostream>
#include <string>
#include <algorithm>
#define tab "\n"
using namespace std;


const string INT_ERROR = "Not a numeric value entered!";
const string NO_DISCR = "This is not a quadratic equation! ";
const string NO_INT_DISCR = "The discriminate is not considered an integer! ";


void IntProof()
{
	if (cin.fail() or cin.peek() != 10)
	{
		throw INT_ERROR;
	}
}


int main()
{
	setlocale(LC_ALL, "RU");

	double a, b, c;
	int discr = 0;
	double koren1, koren2 = 0;
	int check = 0;


	try
	{
		cout << "Enter the value of the coefficients a, b, c: " << endl;
		cin >> a >> b >> c;
		IntProof();
		cout << "Variable input a: " << a << tab << "Variable input b: " << b << tab << "Variable input c: " << c << endl;

		if (a == 0) throw NO_DISCR;
		else
		{
			discr = pow(b, 2) - (4 * a * c);
			check = sqrt(discr);
			if (check < 0) cout << "No roots! ";
			else
			{
				if (check * check == discr)
				{
					if (check == 0) { koren1 = (-b) / (2 * a); cout << "root = " << koren1; }
					else
					{
						koren1 = (-b + check) / (2 * a);
						koren2 = (-b - check) / (2 * a);

						cout << "root 1 = " << koren1 << tab << "root 2 = " << koren2 << endl; 
					}
				}
				else throw NO_INT_DISCR;
			}
		}
	}

	catch (const string& error)
	{
		cerr << "An error was caught: " << error;
		return -1;
	}

}