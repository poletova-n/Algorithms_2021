#include <iostream>
#include <cmath>
#include <windows.h>
int main()
{
    try
    {
        SetConsoleOutputCP(CP_UTF8);
        std::cout<<"Введите a,b,c – коэффициенты квадратного уравнения"<<std::endl;
        int a,b,c;
        std::cin>>a>>b>>c;
        int KvUr (int a, int b, int c);
        {
            if (std::cin.fail())
            {
                throw std::exception ("Коэффициенты квадратного уравнения должны быть заданы числами, завершение программы");
            }
            else
            {
                if (a==0)
                    throw std::exception("Коэффициент ‘a’ квадратного уравнения не должен быть равен 0, так как уравнение становится линейным,\n завершение программы");
                else
                {
                    int D = pow(b,2)-4*a*c;
                    if (sqrt(D)-int (sqrt(D))>0)
                        throw  std::exception("дискриминант - иррационален, завершение программы\n");
                    else
                    {
                        if (D<0)
                        {
                            std::cout<<"Корней нет, завершение программы";
                        }
                        if(D==0)
                        {
                            int x;
                            x = -b/(2*a);
                            std::cout<<"Корень уравнения “x” =" <<x<<",завершение программы";
                        }
                        if (D>0)
                        {
                            int x1;
                            x1 =(-b+int (sqrt (D)))/(2*a);
                            int x2;
                            x2=(-b-int (sqrt (D)))/(2*a);
                            std::cout<<"Корень уравнения “x1” =" <<x1<<std::endl<<"Корень уравнения “x2”="<<x2<<","<<std::endl<<"завершение программы";
                        }
                    }
                }
            }
        }
        return 0;
    }
    catch (std::exception &ex)
    {
        std::cerr<<"Error: "<< ex.what();
    }
}

