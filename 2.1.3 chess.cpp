#include <iostream>
using namespace std;

int main()
{
	cout << "enter the coordinates of the elephant in numbers (ex: 1 8 means A 8)" << endl;
	int x, y, x2, y2;
	cin >> x >> y;
	cout << "enter the coordinates of the other figure in numbers (ex: 1 8 means A 8)" << endl;
	cin >> x2 >> y2;
	if ((cin.peek() != '\n') and (x > 8) and (y > 8) and (x2 > 8) and (y2 > 8))//если пользователь ввел неверные данные, выводить ошибку
	{
		cout << "number must be whole and must not over 8" << endl;
	}
	else
	{
		cout << ((x-x2)==(y-y2)) << endl;
	}
}