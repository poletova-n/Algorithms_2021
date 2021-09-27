#include <iostream>
int main ()
{
    int n=1;
    int N=1;
    double a1;
    double a2;
    double max;

    std::cout << "Enter elements (0 - exit):\n";
    std::cin>>a1;
    max=a1;
    if (std::cin.fail())
    {
        std::cout << "wrong input, try again.\n";
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
                    std::cout << "wrong input, try again.\n";
                    break;
                }
                else
                {
                    if (a2>max)
                    {
                        max = a2;
                        N=n;
                    }
                    a1=a2;
                }
                if (a2==0)
                {
                    std::cout<<"highest  number is "<<max<<' ';
                    std::cout<<"nomer "<<N<<std::endl;
                    break;
                }
            }
    }
}