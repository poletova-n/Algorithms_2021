#include <iostream>
int main ()
{
    int N; //kolvo simvolov v stroke
    std::cout<<"Enter side length of a triangle "<<std::endl;
    std::cin>>N;
    if (std::cin.fail()||(N<=0))
    {
        std::cout << "wrong input, try again.\n";
    }
    else
        for (int n=1;n<=N;n++)
        {

            std::string XD(std::string(N*2+1,' ')); //для пробелов между звездочками.
            for (int a = N-n,b=N; a != N;a++, b--)
            {
                XD.replace(b,1,"* ");
            }
            std::cout<<XD<<std::endl;
        }
}