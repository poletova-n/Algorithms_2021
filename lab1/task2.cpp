#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout<<"Введите число ворон в стае"<<endl;
    int N;
    cin>>N;

    if (cin.good()==false) //проверка на число
        cout<<"Число ворон в стае должно быть задано числом, завершение программы";
    else
    {
        if (N==0) //проверка на 0
            cout<<"В стае нет ворон, завершение программы"<<endl;
        else
        {
            if (N<0) //проверка на положительность числа
                cout<<"«Число ворон в стае должно быть задано положительным числом»";
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