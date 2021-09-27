/*
1 ворона
2-4 вороны
5-9 ворон
10-19 ворон это исключительный ряд, который находится с помощью вычисления остатка при делении на 100*/

#include <iostream>
#include <windows.h>
int main()
{
    try
    {
        SetConsoleOutputCP(CP_UTF8);
        std::cout<<"Введите число ворон в стае"<<std::endl;
        int N;
        std::cin>>N;
        if (std::cin.good()==false)
           throw std::exception("Число ворон в стае должно быть задано числом, завершение программы\n");
        else
        {
            if (N==0)
               throw std::exception("В стае нет ворон, завершение программы\n");
            else
            {
                if (N<0)
                   throw std::exception("«Число ворон в стае должно быть задано положительным числом»\n");
                else
                {
                    if ((N%100<10)||(N%100>19))
                    {
                        if (N%10==1)
                            std::cout<<"В стае "<<N<<" ворона"<<std::endl;
                        if ((N%10>=2)&&(N%10<=4))
                            std::cout<<"В стае "<<N<<" вороны"<<std::endl;
                        if (((N%10>=5)&&(N%10))||(N%10==0))
                            std::cout<<"В стае "<<N<<" ворон"<<std::endl;
                    }
                    else
                        std::cout<<"В стае "<<N<<" ворон";
                    return 0;
                }
            }
        }
    }
    catch (std::exception &ex)
    {
        std::cout<<"Error: "<< ex.what();
    }

}
