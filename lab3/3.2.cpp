#include <iostream>
#include <windows.h>
using namespace std;
const char* error_value_not_number = "Число ворон в стае должно быть задано числом, завершение программы";
const char* error_value_zero = "«Число ворон в стае должно быть задано положительным числом, которое больше нуля»";
int main()
{
    try
    {
        SetConsoleOutputCP(CP_UTF8);
        cout<<"Введите число ворон в стае"<<endl;
        int N;
        cin>>N;

        if (cin.good()==false) //проверка на число
            throw error_value_not_number;
        else
        {
            if (N==0) //проверка на 0
                throw error_value_zero;
            else
            {
                if (N<0) //проверка на положительность числа
                    throw error_value_zero;
                else
                {
                    if ((N%100<10)||(N%100>19))
                    {
                        if (N%10==1)
                            cout<<"В стае "<<N<<" ворона"<<endl;

                        if ((N%10>=2)&&(N%10<=4))
                            cout<<"В стае "<<N<<" вороны"<<endl;

                        if ((N%10>=5)||(N%10==0))
                            cout<<"В стае "<<N<<" ворон"<<endl;

                    }
                    else
                        cout<<"В стае "<<N<<" ворон";

                    return 0;
                }
            }
        }
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}