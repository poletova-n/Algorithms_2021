#include <iostream>
using namespace std;

int main()
{
	cout << "enter the coordinates of the queen in numbers (ex: 1 8 means A 8)" << endl;
	int x, y, x2, y2;
	cin >> x >> y;
	cout << "enter the coordinates of the other figure in numbers (ex: 1 8 means A 8)" << endl;
	cin >> x2 >> y2;
	if ((cin.peek() != '\n') || (x > 8) || (x < 0) || (y > 8) || (y < 0) || (x2 > 8) || (x2 < 0) || (y2 > 8) || (y2 < 0))//если пользователь ввел неверные данные, выводить ошибку
	{
		cout << "number must be whole and must < 8 and > 0 " << endl;
	}
	else
	{
		cout << (((x == x2) || (y == y2)) ||((x - x2) == (y - y2)) )<< endl;
	}
}