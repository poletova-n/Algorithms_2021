#include <iostream>

using namespace std;

int main()
{
	cout << "enter the coordinates of two points x1 y1, x2, y2" << endl; //ввести координаты двух точек: х1, у1, х2, у2
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2>> y2;
	if ((cin.peek() != '\n') || (x1==0) || (x2 == 0) || (y1 == 0) || (y2 == 0)) //если координаты равны нулю или введено не число, то выдавать ошибку
	{
		cout << "number must be whole and must not be zero" << endl;
	}
	else
	{
		if ((x1 * x2 > 0) and (y1 * y2 > 0)) //если знаки произведения сходятся, то выводим ответ ДА
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}