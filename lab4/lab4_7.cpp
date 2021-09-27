#include <iostream>
int main()
{
    int a=0;
    int b=0;
    std::cout<<"Enter bishop's coordinates"<<std::endl;
    std::cin>>a;
    std::cin>>b;
    if (std::cin.fail()||(a<1 ||a>8 || b<1 ||b>8))
    {
        std::cerr << "wrong input, try again.\n";
    }
    else
    {
        int x=a;
        int y=b;
        if ((x==1&&y==1)||(x==1&&y==8)||(x==8&&y==1)||(x==8&&y==8)) {
            if ((x == 1 && y == 1) || (x == 8 && y == 8))
            {
                for(;x>1 && x<=8 && y>1 && y<=8;x--,y--);
                for(;x>=1 && x<=8 && y>=1 && y<=8;x++,y++)
                    std::cout<<x<<" "<<y<<std::endl;
            }
            if ((x==8&&y==1)||(x==1&&y==8))
            {
                for(;x>1 && x<=8 && y>=1 && y<8;x--,y++);
                for(;x>=1 && x<=8 && y>=1 && y<=8;x++,y--)
                    std::cout<<x<<" "<<y<<std::endl;
            }
        }
        else
        {
            for(;x>1 && x<=8 && y>1 && y<=8;x--,y--);
            for(;x>=1 && x<=8 && y>=1 && y<=8;x++,y++)
                std::cout<<x<<" "<<y<<std::endl;
            x=a;
            y=b;
            for(;x>1 && x<=8 && y>=1 && y<8;x--,y++);
            for(;x>=1 && x<=8 && y>=1 && y<=8;x++,y--)
                std::cout<<x<<" "<<y<<std::endl;
        }
    }
}
