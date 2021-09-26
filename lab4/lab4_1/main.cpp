#include <iostream>
int main ()
{
    double a1;
    double a2;
    double count;
    double sum=0;
    std::cout << "Enter elements (0 - exit):\n";
    std::cin>>a1;
    sum+=a1;
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
                a1=a2;
                sum+=a1;
            }
            if (a2==0)
            {
                count = (sum);
                std::cout<<"Sum equal to "<<count<<std::endl;
                break;
            }
        }
    {
    }
}
