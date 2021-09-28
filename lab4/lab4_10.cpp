#include <iostream>
int main ()
{
    int N;
    std::cout<<"Enter side length of a Rhomb "<<std::endl;
    std::cin>>N;
    if (std::cin.fail()||(N<=0))
    {
        std::cout << "wrong input, try again.\n";
    }
    else
        for (int n=1;n<=N;n++)
        {
            std::string XD(std::string(N*2+1,' ')); //Создаёт полянку из пробелов =)
            for (int a = N-n,b=N; a != N;a++, b--)
            {
                XD.replace(b,1,"* "); //Меняет, где нужно пробелы на звездочки =)
            }
            std::cout<<XD<<std::endl;
        }
    // ↑ Сверху ↑ ☻ рекурсия на создание верхней части ромба + центральной линии, а ↓ ниже ↓ рекурсия на нижнюю часть. =)
    for (int n=N-1;n>0;n--)
    {
        std::string XD(std::string(N*2+1,' ')); //для пробелов между звездочками.
        for (int a = N-n,b=N; a != N;a++, b--)
        {
            XD.replace(b,1,"* ");
        }
        std::cout<<XD<<std::endl;
    }
}