#include <iostream>
int main()
{
    int a, b, count=0;
    std::cout << "Enter elements (0 - exit (after enter 1st element)):\n";
    std::cin >> b;
    if (b==0)
    {
        std::cout<<"1st number cant be 0 or letter";
    }
    else
    {
        while (true)
        {
            std::cin >> a;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cout << "wrong input, try again.\n";
                break;
            }
            else
            {
                if (a==0)
                {
                    std::cout << "count=" << count << "\n";
                    break;
                }
                if ((a>0 && b<0) || (a<0 && b>0))
                    count++;
                b=a;
            }
        }
        return 0;
    }
}
