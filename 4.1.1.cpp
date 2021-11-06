#include <iostream>

using namespace std;

int main()
{
	int a, b; //a - number, b - summ
	a = 1;
	b = 0;
	while (a != 0)
	{
		cout << "enter the number"<<endl;
		cin >> a;
		if (cin.peek() != '\n') //проверяем условия: коэффициенты - числа
		{
			cout << "a cant be a letter"<<endl;
		}
		else
		{
			b = b + a;
			cout << "summ: " << b << endl;
		}
	}

}