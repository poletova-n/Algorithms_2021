#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string NO_INT = " Vvedeno ne tcheloe chiclo! ";
const string NE_V_POLE = " Koordinati ne pravilnie!";
const string NO_FIGUR = " Takou figuri net!";
const string NO_MAKE = " Takou figuru ne narisovat!";

inline void IntProof()
{
	if (cin.fail() or cin.peek() != 10)
	{
		throw NO_INT;
	}

}

inline int IsCorrect(int x, int y)
{
	if ((x < 1) or (x > 8) or (y < 1) or (y > 8))
	{
		throw NE_V_POLE;
	}

	return x, y;
}




int main()
{

	setlocale(LC_ALL, "RU");

	int lenght = 0;

	cout << "Vvedite rasmer storoni romba: " << endl;

	try
	{
		cin >> lenght;
		IntProof();
		if (lenght <= 0) throw  NO_FIGUR;
		if (lenght < 2) throw NO_MAKE;
	}
	catch (const string& error)
	{
		cerr << error;
		return -1;
	}


	for (int i = 0; i < lenght; i++)
	{
		for (int j = 1; j < lenght - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i * 2; j++)
		{
			cout << "*";
		}
		cout << endl;
	}



	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < (lenght - i) * 2 - 3; j++)
		{
			cout << "*";
		}
		cout << endl;
	}





	//int lenght = 0;

	//cout << "Vvedite rasmer storoni treugolnika1: " << endl;

	//try
	//{
	//	cin >> lenght;
	//	IntProof();
	//	if (lenght <= 0) throw  NO_FIGUR;
	//	if (lenght < 2) throw NO_MAKE;
	//}
	//catch (const string& error)
	//{
	//	cerr << error;
	//	return -1;
	//}


	//for (int i = 0; i < lenght; i++)
	//{
	//	for (int j = 1; j < lenght - i; j++)
	//	{
	//		cout << " ";
	//	}
	//	for (int j = 0; j <= i * 2; j++)
	//	{
	//		cout << "*";
	//	}
	//	cout << endl;
	//}












//
//int lenght = 0;
//
//	cout << "Vvedite rasmer kvadrata A x A: " << endl;
//
//	try
//	{
//		cin >> lenght;
//		IntProof();
//	}
//	catch (const string& error)
//	{
//		cerr << error;
//		return -1;
//	}
//	
//
//	for (int i = 0; i < lenght; i++)
//	{
//		cout << "  ";
//		for (int j = 0; j < lenght; j++)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}
//













	/*int x1, y1 = 0;

	try
	{
		cout << "Vvedite koordinati slona " << endl;
		cin >> x1 >> y1;
		IntProof();
		cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		IsCorrect(x1, y1);

	}
	catch (const string& error)
	{
		cerr << error;
		return -1;
	}

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if ((x1 == i) and (y1 == j))
			{
				continue;
			}

			if (abs(x1 - i) == abs(y1 - j))
			{
				cout << "Moshno s'est figuru: (" << i << "," << j << ")" << endl;
			}

		}
	}*/









	/*int x1, y1 = 0;

	try
	{
		cout << "Vvedite koordinati ladia " << endl;
		cin >> x1 >> y1;
		IntProof();
		cout << "X = " << x1 << " " << "Y = " << y1 << endl << endl;
		IsCorrect(x1, y1);

	}
	catch (const string& error)
	{
		cerr << error;
		return -1;
	}

	for (int i = 1 ; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if ((x1 == i) and (y1 == j))
			{
				continue;
			}

			if (x1 == i)
			{
				cout << "Moshno s'est figuru: (" << i << "," << j << ")" << endl;
			}

			if (y1 == j)
			{
				cout << "Moshno s'est figuru: (" << i << "," << j << ")" << endl;
			}

		}
	}*/












	//   int input = 0;
	//   int min = numeric_limits<int>::max();
	   //int prevcal = 0;
	   //int cal = 0;
	   //int inf = 0;
	   //cout << "Vvodite chicla: " << endl;
	   //cout << "Vvedite 0, programma zakonchit" << endl;

	   //try
	   //{
	   //	while (inf == 0)
	   //	{
	   //		cin >> input;
	   //		IntProof();

	   //		if (input == 0)
	   //		{
	   //			cout << "Min tchislo = " << min << endl;
	   //			cout << "Nomer tschicla = " << cal;
	   //			break;
	   //		}
	   //		else if (input > 0)
	   //		{
	   //			prevcal++;
	   //			if (input < min)
	   //			{
	   //				min = input;
	   //				cal = prevcal;
	   //			}
	   //		}
	   //		else
	   //		{
	   //			prevcal++;
	   //			continue;
	   //		}
	   //	}
	   //}
	   //catch (const string& error)
	   //{
	   //	cerr << error;
	   //	return -1;
	   //}














	   //int input = 0;;
	   //int max = numeric_limits <int> ::min();;
	   //int prevcal = 0;
	   //int cal = 0;
	   //int inf = 0;
	   //cout << "Vvodite chicla: " << endl;
	   //cout << "Vvedite 0, programma zakonchit" << endl;

	   //try
	   //{
	   //	while (inf == 0)
	   //	{
	   //		cin >> input;
	   //		IntProof();

	   //		if (input == 0)
	   //		{
	   //			cout << "Max tchislo = " << max << endl;
	   //			cout << "Nomer tschicla = " << cal;
	   //			break;
	   //		}
	   //		else
	   //		{
	   //			prevcal++;
	   //			if (max < input)
	   //			{
	   //				max = input;
	   //				cal = prevcal;
	   //			}
	   //		
	   //		}


	   //	}
	   //}
	   //catch (const string& error)
	   //{
	   //	cerr << error;
	   //	return -1;
	   //}













	   int input = 0;
	   double average = 0.0;
	   int cal = 0;
	   int inf = 0;

	   cout << "Vvodite chicla: " << endl;
	   cout << "Vvedite 0, programma zakonchit" << endl;
	   try
	   {
		   while (inf == 0)
		   {
			   cin >> input;
			   IntProof();

			   if (input == 0)
			   {
				   cout << "srednee znachenit = " << average / cal;
				   break;
			   }
			   else if (input > 0)
			   {
				   cal++;
				   average += input;
			   }
			   else
			   {
				   continue;
			   }
		   }
	   }
	   catch (const string& error)
	   {
		   cerr << error;
		   return -1;
	   }









	   /*int input = 0;
	   double average = 0.0;
	   int cal = 0;
	   int inf = 0;
	   cout << "Vvodite chicla: " << endl;
	   cout << "Vvedite 0, programma zakonchit";

	   try
	   {
		   while (inf == 0)
		   {
			   cin >> input;
			   IntProof();

			   if (input == 0)
			   {
				   cout << "Average = " << average / cal;
				   break;
			   }
			   else
			   {
				   cal++;
				   average += input;
			   }


		   }
	   }
	   catch (const string& error)
	   {
		   cerr << error;
		   return -1;
	   }*/









	   /*int input = 0;
	   int sum = 0;
	   int inf = 0;
	   cout << "Vvodite chicla: " << endl;
	   cout << "Vvedite 0, programma zakonchit";
	   try
	   {
		   while (inf == 0)
		   {
			   cin >> input;
			   IntProof();
			   if (input == 0)
			   {
				   cout << "summa = " << sum;
				   break;
			   }
			   else
			   {
				   sum += input;
			   }
		   }
	   }
	   catch (const string& error)
	   {
		   cerr << error;
		   return -1;
	   }*/
}