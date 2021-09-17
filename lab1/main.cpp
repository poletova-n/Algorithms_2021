#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
int main(int argc, char* argv[])
{
	
	SetConsoleOutputCP(65001);

	//double a, b, c;
	//int discr = 0;
	//double koren1, koren2 = 0;
	//int check = 0;

	//cout << "Введите значение коэфицентов a, b, c: " << endl;
	//cin >> a >> b >> c;

	//if (cin.fail() or cin.peek() != 10) // проверка на ввод числа, а не буквы
	//{
	//	cout << "Введите коректные данные!";
	//}
	//else
	//{
	//	cout << "Ввод переменной a: " << a << tab << "Ввод переменной b: " << b << tab << "Ввод переменной c: " << c << endl;

	//	if (a == 0) cout << "Это не квадратное уравнение! Попробуйте ввести ещё раз!"; // проверка на квадратное уравнение 
	//	else
	//	{
	//		discr = pow(b, 2) - (4 * a * c);
	//		check = sqrt(discr);
	//		if (check < 0) cout << "Корней нет! "; // проверка на наличие корней
	//		else
	//		{
	//			if (check * check == discr) // проверка корня, извлекается ли нацело
	//			{
	//				if (check == 0) { koren1 = (-b) / (2 * a); cout << "Корень = " << koren1; }
	//				else
	//				{
	//					koren1 = (-b + check) / (2 * a); // считаем корни
	//					koren2 = (-b - check) / (2 * a);

	//					cout << "Корень 1 = " << koren1 << tab << "Корень 2 = " << koren2 << endl; // вывод корней
	//				}
	//			}
	//			else { cout << "Дискриминат не считается целым числом! "; }
	//		}
	//	}
	//}


	//int cal; 
	//cout << "Введите количество ворон: ";
	//cin >> cal;
	//if (cin.fail() or cin.peek() != 10) //проверка данных
	//{
	//	cout << "Введите корректные данные!";
	//}
	//else
	//{
	//	if ((cal % 10 == 3) or (cal % 10 == 2) or (cal % 10 == 4)) // проверка на какую цифру заканчивается
	//		cout << "В стае " << cal << " вороны";
	//	else if ((cal % 10 == 5) or (cal % 10 == 6) or (cal % 10 == 7) or (cal % 10 == 8) or (cal % 10 == 9))
	//		cout << "В стае " << cal << " ворон";
	//	else if (cal % 10 == 1)
	//		cout << "В стае " << cal << " воронa";
	//}


	int a, b, c;

	cout << "Введите значение трёх сторон: " << endl << endl;
	cout << "Сторона а: ";
	cin >> a;
	cout << endl;

	cout << "Сторона b:  ";
	cin >> b;
	cout << endl;

	cout << "Сторона c: ";
	cin >> c;
	cout << endl;

	if (cin.fail() or cin.peek() != 10) // проверка на число
	{
		cout << "Введите корректные данные!";
	}
	else
	{
		if (pow(c, 2) == pow(b, 2) + pow(a, 2)) cout << "Треугольник прямоугольный!" << endl;;
		if (pow(c, 2) < pow(b, 2) + pow(a, 2)) cout << "Треугольник остроугольный!" << endl;
		if (pow(c, 2) > pow(b, 2) + pow(a, 2)) cout << "Треугольник тупоугольный!" << endl;;
	}

	return 0;
}