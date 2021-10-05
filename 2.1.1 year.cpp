#include <iostream>
using namespace std;

int main()
{
	cout << "enter the year" << endl;
	int y;
	cin >> y;
	if (cin.peek() != '\n') //если пользователь вводит неверное значение, то выводим ошибку
	{
		cout << "year must be whole" << endl;
	}
	else
	{
		cout << (((y % 4 == 0) and (y % 100 != 0)) || (y % 400 == 0)) << endl;
	}
}