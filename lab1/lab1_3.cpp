#include <iostream>
#include <cmath>
#include <windows.h>
int maxInSq(int x,int y,int z) //поиск наибольшей стороны и возведение её в квадрат
{
    if ((x>=y)&&(x>=z))
        return int(pow(x,2));
    if ((y>=x)&&(y>=z))
        return int(pow(y,2));
    if ((z>=x)&&(z>=y))
        return int(pow(z,2));
}
int minsInSq(int x,int y,int z) //поиск суммы меньших сторон и возведение её в квадрат
{
    if ((x>=y)&&(x>=z))
        return int(pow(y,2)+pow(z,2));
    if ((y>=x)&&(y>=z))
        return int(pow(x,2)+pow(z,2));
    if ((z>=x)&&(z>=y))
        return (pow(x,2)+pow(y,2));
}
int main()
{
    try
    {
        SetConsoleOutputCP(CP_UTF8);
        int a,b,c;
        std::cout<<"Введите длины сторон "<<std::endl;
        std::cin>>a>>b>>c;
        if ((a<=0 || b<=0 || c<=0)||(std::cin.good()==false))
            throw std::exception("Длина сторон треугольника должны быть заданы числами, бОльшими нуля\n");
        else
        {
            if (a+b<=c || a+c<=b || b+c<=a)
                throw std::exception("Треугольника с заданными сторонами не существует\n");
            else
            {
                if (a==b && a==c && b==c)
                    std::cout<<"треугольник: равносторонний, ";
                else
                if (a==b || a==c || b==c)
                    std::cout<<"треугольник: равнобедренный, ";
                if (a!=b && a!=c && b!=c)
                    std::cout<<"треугольник: разносторонний, ";
                if (maxInSq(a,b,c)==minsInSq(a,b,c))
                    std::cout<<"прямоугольный" ;
                if (maxInSq(a,b,c)>minsInSq(a,b,c))
                    std::cout<<"тупоугольный" ;
                if (maxInSq(a,b,c)<minsInSq(a,b,c))
                    std::cout<<"остроугольный" ;
            }
        }
    }
    catch (std::exception &error)
    {
        std::cerr<<"Error: "<<error.what();
    }
}
