#include<iostream>
#include<fstream>

using namespace std;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
	/*
	if (c >= '0' && c <= '9')
		return true;
	return false;
	*/
}
bool isSign(char c)
{
	if (c == '+' || c == '-')
		return true;
	return false;
}
bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		/*
		while (isDigit(str[index]))
		{
			++index;
		}*/
		return true;
	}
	return false;
}
bool isOrder(string str, int& index)
{
	if (str[index] == 'E')
	{
		index++;
		if (isNatural(str, index))
		{
			return true;
		}
		if (isSign(str[index]))
		{
			index++;
			if (isNatural(str, index))
			{
				return true;
			}
		}
	}
	return false;
}
bool isMantissa(string str, int& index)
{
	return (str[index] == '.' && isNatural(str, ++index) || isNatural(str, index) && str[index] == '.' && isNatural(str, ++index));
}
bool isReal(string str)
{
	int i = 0;
	return (isMantissa(str, i) && isOrder(str, i) || isSign(str[i]) && isMantissa(str, ++i) && isOrder(str, i));
}

int main()
{
	std::cout << "Check input files";
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	while (!fin.eof())
	{
		string str;
		fin >> str;
		if (isReal(str))
			fout << str << " True" << endl;
		else
			fout << str << " False" << endl;
	}
	fout.close();
	fin.close();
	return 0;
}
