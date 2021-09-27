#include <iostream>
int main()
{
    int a=0;
    int b=0;
    std::cout<<"Enter rook's coordinates"<<std::endl;
    std::cin>>a;
    std::cin>>b;
    if (std::cin.fail()||(a<1 ||a>8 || b<1 ||b>8))
    {
        std::cerr << "wrong input, try again.\n";
    }
    else
    {
        int x=a;
        int y=1;
        for(;x>=1 && x<=8 && y>=1 && y<=8;y++)
            std::cout<<x<<" "<<y<<std::endl;
        x=1;
        y=b;
        for(;x>=1 && x<=8 && y>=1 && y<=8;x++)
            std::cout<<x<<" "<<y<<std::endl;
    }
}
