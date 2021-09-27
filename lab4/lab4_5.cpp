#include <iostream>
int main ()
{
    int n=1;
    int N=1;
    double a1;
    double a2;
    double min;

    std::cout << "Enter elements (0 - exit):\n";
    std::cin>>a1;
    min=a1;
    if (std::cin.fail())
    {
        std::cerr << "wrong input, try again.\n";
    }
    else
    {
        if (a1==0)
            std::cout<<"empty row, end of program";
        else
            while (a1!=0)
            {
                n++;
                std::cin>>a2;
                if (std::cin.fail())
                {
                    std::cerr << "wrong input, try again.\n";
                    break;
                }
                else
                {
                    if (a2==0)
                    {
                        std::cout<<"lowest number is "<<min<<' ';
                        std::cout<<"nomer "<<N<<std::endl;
                        break;
                    }
                    if (a2<min)
                    {
                        min = a2;
                        N=n;
                    }
                    a1=a2;
                }

            }
    }
}