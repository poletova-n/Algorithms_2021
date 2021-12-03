#include <iostream>
#include <cctype>
#include <fstream>
#include <windows.h>
using namespace std;
const char* FILE_NOT_FOUND = "Error - File not found";
const char* UNKNOWN_ERROR = "Error - Unknown error";

int main()
{
	try
	{
		SetConsoleOutputCP(CP_UTF8);
		ifstream rFile;
		rFile.open("C:\\file2.txt");
		if (!rFile.is_open())
		{
			throw FILE_NOT_FOUND;
		}

		ofstream wFile;
		wFile.open("C:\\ans.txt");
		if (!wFile.is_open())
		{
			throw FILE_NOT_FOUND;
		}

		int num = 0;
		int ans = 0;
		while (!rFile.eof())
		{
			if (num > 0)
			{
				wFile <<ans << " matches on line " << num << endl;
			}
			char temp = ' ';
			++num;
			char alph[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
			int lenAlph = (sizeof(alph) / sizeof(*alph));
			ans = 0;
			while (temp != '\\' and !rFile.eof())
			{
				rFile >> temp;
				if (!isalpha(temp)) { continue; } // Проверка на буквы
				else
				{
					if (isupper(temp)) // Из больших в маленькие
					{
						temp = tolower(temp);
					}
				}
				if (islower(temp))
				{
					for (int i = 0; i < lenAlph; i++) // Исключаем совпадения
					{
						if (alph[i] == temp)
						{
							alph[i] = '0';
							ans++;
						}
					}
				}
				else
				{
					throw UNKNOWN_ERROR;
				}
			}

		}

		rFile.close();
		wFile.close();
		return 0;
		
	}
	catch (const char* error)
	{
		cerr << error << endl;
		return -1;
	}
}