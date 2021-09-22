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










	/*int cal = 0;

	cout << "Enter the number of crows: ";

	try
	{
		cin >> cal;
		IntProof();
	}
	catch (const string& error)
	{
		cerr << "Àn error was caught: " << error;
		return -1;
	}

	if ((cal % 10 == 3) or (cal % 10 == 2) or (cal % 10 == 4))
		cout << "V stae " << cal << " voroni";
	else if ((cal % 10 == 5) or (cal % 10 == 6) or (cal % 10 == 7) or (cal % 10 == 8) or
		(cal % 10 == 9) or (cal % 100 == 11) or (cal % 100 == 12) or (cal % 100 == 13) or (cal % 100 == 4))
		cout << "V stae " << cal << " voron";
	else if (cal % 10 == 1)
		cout << "V stae " << cal << " vorona";*/







	//cout << "Enter the value of the three sides in ascending order: " << endl << endl;
	//int a, b, c = 0;
	//try
	//{
	//	cout << "Side a ";
	//	cin >> a;
	//	IntProof();
	//	cout << endl;

	//	cout << "Side  b: ";
	//	cin >> b;
	//	IntProof();
	//	cout << endl;

	//	cout << "Side  c: ";
	//	cin >> c;
	//	IntProof();
	//	cout << endl;

	//}
	//catch (const string& error)
	//{
	//	cerr << "Àn error was caught: " << error;
	//	return -1;
	//}


	//if ((a < 0) or (b < 0) or (c < 0))
	//{
	//	cout << "There is no such triangle!";
	//	return -1;
	//}

	//if ((a + b) <= c)
	//{
	//	cout << "There is no such triangle!";
	//	return -1;
	//}

	//if (pow(c, 2) == pow(b, 2) + pow(a, 2))
	//{
	//	cout << "The triangle is rectangular!" << endl;
	//	return -1;
	//}

	//if (pow(c, 2) < pow(b, 2) + pow(a, 2))
	//{
	//	cout << "Acute triangle!" << endl;
	//	return -1;
	//}

	//if (pow(c, 2) > pow(b, 2) + pow(a, 2))
	//{
	//	cout << "The triangle is obtuse!" << endl;
	//	return -1;
	//}

}