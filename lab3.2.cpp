
#include <iostream>
using namespace std;
const string ERROR_NOT_NUMBER = "error! enter the NUMBER";

const string ERROR_NOT_POSITIVE_NUMBER = "error! enter positive number";
int main() {
	try {
		int n(0);
		cout << "vvedite kolichestvo voron: \n";
		cin >> n;
		if (cin.fail() || cin.peek() != 10) {
			throw ERROR_NOT_NUMBER;
		}
		else if (n < 0) {
			throw ERROR_NOT_POSITIVE_NUMBER;
		}
		else;
	if (((n >= 11) and (n <= 19)) || (n % 10 == 0 || n % 10 == 5 || n % 10 == 6 || n % 10 == 7 || n % 10 == 8 || n % 10 == 9))
		/*проверяем условия: N от 11 до 19, остаток от деления на 10 равен 0, 5, 6, 7, 8, 9*/
	{
		cout << "zdes " << n << " voron.";
	}
	else
	{
		if (n % 10 == 1) //проверяем условия: остаток от деления равен 1
		{
			cout << "zdes " << n << " vorona.";
		}
		else
		{
			cout << "zdes " << n << " vorony.";
		}
	}
	}
	catch (const string& error) {
		cerr << endl << error << endl;
		return -1;
	}
}
