#include <iostream>
int main ()
{
    double a1;
    double a2;
    int count=0;
    std::cout << "Enter elements (0 - exit):\n";
    std::cin>>a1;
    if (a1==0)
        std::cout<<"empty row, end of program";
    else
        while (a1!=0)
        {
            std::cin>>a2;
            if (std::cin.fail())
            {
                std::cout << "wrong input, try again.\n";
                break;
            }
            else
            {
                if ((a1>0 && a2<0) || (a1<0 && a2>0))
                    count++;
                a1=a2;
            }
            if (a2==0)
            {
                std::cout << "sign change=" << count << "\n";
                break;
            }
        }
    {
    }
}


























