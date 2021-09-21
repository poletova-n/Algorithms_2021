#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout<<"Введите число ворон в стае"<<std::endl;
    int N;
    std::cin>>N;

    if (std::cin.good()==false) //проверка на число
        std::cout<<"Число ворон в стае должно быть задано числом, завершение программы";
    else
    {
        if (N==0) //проверка на 0
            std::cout<<"В стае нет ворон, завершение программы"<<std::endl;
        else
        {
            if (N<0) //проверка на положительность числа
                std::cout<<"«Число ворон в стае должно быть задано положительным числом»";
            else
            {
                if ((N%100<10)||(N%100>19))
                {
                    if (N%10==1)
                        std::cout<<"В стае "<<N<<" ворона"<<std::endl;

                    if ((N%10>=2)&&(N%10<=4))
                        std::cout<<"В стае "<<N<<" вороны"<<std::endl;

                    if ((N%10>=5)||(N%10==0))
                        std::cout<<"В стае "<<N<<" ворон"<<std::endl;

                }
                else
                    std::cout<<"В стае "<<N<<" ворон";

                return 0;

            }

        }

    }

}