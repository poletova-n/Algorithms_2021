#include <iostream>
#include <string>
#include <algorithm>
#define tab "/t"
using namespace std;

int Choose;
void IntProof();

inline void ChooseValue()
{
	string Figurs[4] = { "Конь", "Слон ", "Ладья", "Ферзь" };

	cout << "Выберите нужную вам цифру: " << endl << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". " << Figurs[i] << endl;
	}

	cout << endl;
	cout << "Ваш выбор: ";
	cin >> Choose;
	IntProof();
	cout << endl;
}

inline void IntProof()
{
	if (cin.fail() or cin.peek() != 10)
	{
		cout << "Введите числовой тип данных!";
		exit(1);
	}
}

inline void isCorrect(int x, int y)
{
    if ((x < 1) or (x > 8) or (y < 1) or (y > 8))
	{
		cout << "Введите правильно координаты фигуры!";
		exit(1);
	}
}


int main()
{
	setlocale(LC_ALL, "RUSSIAN");


	/*int x1, y1, x2, y2;


	ChooseValue();
	switch (Choose)
	{
	  case 1:
		  cout << "Введите координаты Коня: " << endl;
		  cin >> x1 >> y1;
		  IntProof();
		  cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		  isCorrect(x1, y1);


		  cout << "Введите координаты любой фигуры: " << endl;
		  cin >> x2 >> y2;
		  IntProof();
		  cout << "X = " << x2 << " " << "Y = " << y2 << endl;
		  isCorrect(x2, y2);


		  if (((abs(x1 - x2) + abs(y1 - y2) == 3)) and (abs(x1 - x2) != 0) and (abs(y1 - y2) != 0))
		  {
			  cout << "Фигура сьедена!";
		  }
		  else cout << "Фигура не сьедена!";

		  break;
	  case 2:

		  cout << "Введите координаты Слона: " << endl;
		  cin >> x1 >> y1;
		  IntProof();
		  cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		  isCorrect(x1, y1);


		  cout << "Введите координаты любой фигуры: " << endl;
		  cin >> x2 >> y2;
		  IntProof();
		  cout << "X = " << x2 << " " << "Y = " << y2 << endl;
		  isCorrect(x2, y2);


		  if (abs(x1 - x2) == abs(y1 - y2))
		  {
			  cout << "Фигура сьедена!";
		  }
		  else cout << "Фигура не сьедена!";

		  break;
	  case 3:

		  cout << "Введите координаты ладьи: " << endl;
		  cin >> x1 >> y1;
		  IntProof();
		  cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		  isCorrect(x1, y1);


		  cout << "Введите координаты любой фигуры: " << endl;
		  cin >> x2 >> y2;
		  IntProof();
		  cout << "X = " << x2 << " " << "Y = " << y2 << endl ;
		  isCorrect(x2, y2);


		  if ((x1 == x2) or (y1 == y2))
		  {
			  cout << "Фигура сьедена!";
		  }
		  else cout << "Фигура не сьедена!";

		  break;

	  case 4:

		  cout << "Введите координаты Ферзя: " << endl;
		  cin >> x1 >> y1;
		  IntProof();
		  cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		  isCorrect(x1, y1);


		  cout << "Введите координаты любой фигуры: " << endl;
		  cin >> x2 >> y2;
		  IntProof();
		  cout << "X = " << x2 << " " << "Y = " << y2 << endl;
		  isCorrect(x2, y2);

		  if ((x1 == x2) or (y1 == y2) or (abs(x1 - x2) == abs(y1 - y2)))
		  {
			  cout << "Фигура сьедена!";
		  }
		  else cout << "Фигура не сьедена!";

		  break;
	default:
		cout << "Вы ввели неверную опцию! Попробуйте еще раз!" << endl;
		break;
	}*/


	//int year;
	//cout << "Введите год: " << endl;
	//cin >> year;
	//bool check = true;
	//IntProof();
	//if (((year % 4 == 0) or (year % 400 == 0)) and (year % 100 != 0))
	//{
	//	check = true;
	//}
	//else
	//{
	//	check = false;
	//}
	//
	//if (check)
	//{
	//  cout << "Год високосный!";
	//}
	//else
	//{
	//	cout << "Год не високосный!";
	//}







	//int a, b, c;
	//
	//cout << "Введите три числа: " << endl;
	//cin >> a >> b >> c;
	//IntProof();
	//cout << "Максимальное из 3 чисел является: " << max(max(a, b), c) <<  endl;







	//int a, b, c;
	//int max1 = 0;
	//int min1 = 0;
	//int sr = 0;
	//
	//cout << "Введите три числа: " << endl;
	//cin >> a >> b >> c;
	//IntProof();
	//
	//
	//if (a > b)
	//{
	//	if (a > c)
	//	{
	//		max1 = a;
	//		if (b > c)
	//		{
	//			min1 = c;
	//			sr = b;
	//		}
	//		else
	//		{
	//			min1 = b;
	//			sr = c;
	//		}
	//	}
	//	else
	//	{
	//		max1 = c;
	//		min1 = b;
	//		sr = a;
	//	}
	//	
	//}
	//else
	//{
	//	if (b > c)
	//	{
	//		max1 = b;
	//		if (a > c)
	//		{
	//			min1 = c;
	//			sr = a;
	//		}
	//		else
	//		{
	//			min1 = a;
	//			sr = c;
	//		}
	//    }
	//	else  
	//	{
	//		max1 = c;
	//		min1 = a;
	//		sr = b;
	//	}
	//
	//	
	//}
	//cout << "Числа в порядке неубывания: " << min1 << " " << sr << " " << max1 << endl;






	//
	//int a, b, c;
	//int cal = 0;
	//cout << "Введите три числа: " << endl;
	//cin >> a >> b >> c;
	//IntProof();
	//
	//if ((a == b) and (a == c))
	//{
	//	cal += 3;
	//}
	//else if ((a == b) or (a = c) or (b == c))
	//{
	//	cal += 2;
	//}
	//else
	//{
	//	cal = 1;
	//}
	//
	//cout << "Количество одинаковых введеных чисел: " << cal << endl;







	//int a, b, c;
	//cout << "Введите три числа: " << endl;
	//cin >> a >> b >> c;
	//IntProof();
	//
	//if (((a % 2 == 0) or (b % 2 == 0) or (c % 2 == 0)) and 
	//	((a % 2 != 0) or (b % 2 != 0) or (c % 2 != 0)))
	//{
	//	cout << "ДА" << endl;
	//}
	//else
	//{
	//	cout << "Нет" << endl;
	//}




	int x1, y1, x2, y2;
	bool check = true;
	cout << "Введите координаты двух точек отличные от 0: " << endl;
	cout << "Координата первой точки: ";
	cin >> x1 >> y1;
	cout << "X = " << x1 << " Y = " << y1 << endl;
	IntProof();
	cout << endl;
	cout << "Координата второй точки: ";
	cin >> x2 >> y2;
	cout << "X = " << x2 << " Y = " << y2 << endl;
	IntProof();
	cout << endl;

	if ((x1 == 0) or (x2 == 0) or (y1 == 0) or (y2 == 0))
	{
		cout << "Введите координаты отличные от нуля!";
		return -1;
	}
	else
	{
		if (((x1 > 0) and (y1 > 0)) and ((x2 > 0) and (y2 > 0)))
		{
			cout << "Да" << endl;
			return -1;
		}
		else
		{
			check = false;
		}


		if (((x1 < 0) and (y1 > 0)) and ((x2 < 0) and (y2 > 0)))
		{
			cout << "Да" << endl;
			return -1;
		}
		else
		{
			check = false;
		}

		if (((x1 < 0) and (y1 < 0)) and ((x2 < 0) and (y2 < 0)))
		{
			cout << "Да" << endl;
			return -1;
		}
		else
		{
			check = false;
		}


		if (((x1 > 0) and (y1 < 0)) and ((x2 > 0) and (y2 < 0)))
		{
			cout << "Да" << endl;
			return -1;
		}
		else
		{
			check = false;
		}

		if (!check)
		{
			cout << "Нет" << endl;
		}
	}


	return 0;
}