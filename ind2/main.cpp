#include <iostream>
#include <string>
using namespace std;

const string LIMIT_OVERFLOW = "Vi zashli za predel X (-1, 1) !";
const string NO_INT = "This is not Integer or Double!";
const string LIMIT_POGR = "Bolshe predela pogreshnosti!";
const string NO_GOOD = "Oshibka vicheslenii! ";
const string POLOGITELNOE = "Nelzya vvodit chisla < 0 !";

double fact(double cnt);
double square(double x, double& cal);
int znaks(int& znak);

inline void IsInteger()
{
	if (cin.fail() or cin.peek() != 10)
	{
		throw NO_INT;
	}
}

inline void IsPredel(int x)
{
	if ((x >= 1) or (x <= -1))
	{
		throw LIMIT_OVERFLOW;
	}
}

inline void CheckAbs(double sum, double abs)
{
	if (sum > abs)
	{
		throw LIMIT_POGR;
	}
}


int main()
{
	double x = 0;
	double absError = 0.0;
	int numbermax = 0;
	double cal = 0.0;
	double cnt = 3.0;
	int znak = 1;
	double sum = 0.0;
	double sumfunc = 1.0;
	int i = 0;

	try
	{
		cout << "Vvedite X v predele (-1, 1): ";
		cin >> x;
		IsInteger();
		IsPredel(x);

		cout << "Vvedite kolichestvo slagaemich: ";
		cin >> numbermax;
		IsInteger();
		if (numbermax <= 0) throw POLOGITELNOE;

		cout << "Vvedite pogreshnost': ";
		cin >> absError;
		IsInteger();
		if (absError <= 0) throw POLOGITELNOE;

		do
		{
			sum = square(x, cal) / fact(cnt) * znaks(znak);
			CheckAbs(sum, absError);
			sumfunc += sum;
			cnt += 2;
			i++;
		} while (i < numbermax and sum > absError);

		if (sum > absError) throw NO_GOOD;


		cout << "Function sin(x)/x = " << sumfunc;
	}
	catch (const string& error)
	{
		cerr << "We catch: " << error;
		return -1;
	}




}



double square(double x, double& cal)
{
	double sq = 1.0;
	cal += 2.0;
	for (int i = 0; i < cal; i++)
	{
		sq *= x;
	}
	return sq;
}


double fact(double cnt)
{
	if (cnt == 0) return 0;
	if (cnt == 1) return 1;

	double sum = 0.0;
	sum = cnt * fact(cnt - 1) * 1.0;
	return sum;
}


inline int znaks(int& znak)
{
	if (znak % 2 == 0)
	{
		znak++;
		return 1;
	}
	else
	{
		znak++;
		return -1;
	}
}
