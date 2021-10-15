#include <iostream>
using namespace std;

int main()
{
	int year = 0;
	int visokosniy = 1;
	int nevisokosniy = 0;
	cout << "Enter year: ";
	cin >> year;
	if (cin.fail() || cin.peek() != 10) // проверка на корректность вводимых чисел
	{
		cout << "eRror 404";
	}
	else if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // проверка условий высокосного года
	{
		cout << visokosniy << "\n" << "this is a leap year";
	}
	else
	{
		cout << nevisokosniy << "\n" << "this is not a leap year";
	}
}
