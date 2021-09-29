
#include <iostream>
using namespace std;
void main()
{
	cout << "enter the WHOLE number of crows in the flock\n";
	short N;
	cin >> N; //вводим количество ворон
	if (((N >= 11) and (N <= 19)) || (N % 10 == 0 || N % 10 == 5 || N % 10 == 6 || N % 10 == 7 || N % 10 == 8 || N % 10 == 9))
		/*проверяем условия: N от 11 до 19, остаток от деления на 10 равен 0, 5, 6, 7, 8, 9*/
	{
		cout << "zdes " << N << " voron.";
	}
	else
	{
		if (N % 10 == 1) //проверяем условия: остаток от деления равен 1
		{
			cout << "zdes " << N << " vorona.";
		}
		else
		{
			cout << "zdes " << N << " vorony.";
		}
	}
}