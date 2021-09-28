#include <iostream>
#include <sstream>
#include<algorithm>
int Rook (int x1,int y1, int x2, int y2)
{
    if (x1==x2 || y1==y2)
        std::cout<<"Rook ate the chessman";
    else
        std::cout<<"Rook didn't eat the chessman";
    return 0;
}
int Bishop (int x1,int y1, int x2, int y2)
{
    if ((x1 - x2 == y1 - y2))
        std::cout<<"Bishop ate the chessman";
    else
        std::cout<<"Bishop didn't eat the chessman";
    return 0;
}
int Queen (int x1,int y1, int x2, int y2)
{
    if ((x1==x2 || y1==y2) || ((x1 - x2 == y1 - y2)))
        std::cout<<"Queen ate the chessman";
    else
        std::cout<<"Queen didn't eat the chessman";
    return 0;
}
int Knight (int x1,int y1, int x2, int y2)
{
    if ((x1+1==x2 && y1+2==y2) || (x1+1==x2 && y1-2==y2) || (x1+2==x2 && y1+1==y2) || (x1+2==x2 && y1-1==y2)\
     || (x1-1==x2 && y1-2==y2) || (x1-1==x2 && y1+2==y2) || (x1-2==x2 && y1-1==y2) || (x1-2==x2 && y1+1==y2))
        std::cout<<"Knight ate the chessman";
    else
        std::cout<<"Knight didn't eat the chessman";
    return 0;
}
int chess_rules1()
{
    int a1;
    int b1;
    int a2;
    int b2;
    std::cout<<"Enter rook coordinates (min 1, max 8)"<<std::endl;
    std::cin>>a1>>b1;
    std::cout<<"Enter chessman's coordinates"<<std::endl;
    std::cin>>a2>>b2;
    if ((a1<=0 || a1>=9)||(b1<=0 || b1>=9) || (a2<=0 || a2>=9)||(b2<=0 || b2>=9))
    {
        std::cout<<"Enter wrong coordinates, try again"<<std::endl;
    }
    else
        Rook(a1,b1,a2,b2);
    return 0;
}
int chess_rules2()
{
    int a1;
    int b1;
    int a2;
    int b2;
    std::cout<<"Enter Bishop coordinates (min 1, max 8)"<<std::endl;
    std::cin>>a1>>b1;
    std::cout<<"Enter chessman's coordinates"<<std::endl;
    std::cin>>a2>>b2;
    if ((a1<=0 || a1>=9)||(b1<=0 || b1>=9) || (a2<=0 || a2>=9)||(b2<=0 || b2>=9))
    {
        std::cout<<"Enter wrong coordinates, try again"<<std::endl;
    }
    else
        Bishop(a1,b1,a2,b2);
    return 0;
}
int chess_rules3()
{
    int a1;
    int b1;
    int a2;
    int b2;
    std::cout<<"Enter Queen coordinates (min 1, max 8)"<<std::endl;
    std::cin>>a1>>b1;
    std::cout<<"Enter chessman's coordinates"<<std::endl;
    std::cin>>a2>>b2;
    if ((a1<=0 || a1>=9)||(b1<=0 || b1>=9) || (a2<=0 || a2>=9)||(b2<=0 || b2>=9))
    {
        std::cout<<"Enter wrong coordinates, try again"<<std::endl;
    }
    else
        Queen(a1,b1,a2,b2);
    return 0;
}
int chess_rules4()
{
    int a1;
    int b1;
    int a2;
    int b2;
    std::cout<<"Enter Knight coordinates (min 1, max 8)"<<std::endl;
    std::cin>>a1>>b1;
    std::cout<<"Enter chessman's coordinates"<<std::endl;
    std::cin>>a2>>b2;
    if ((a1<=0 || a1>=9)||(b1<=0 || b1>=9) || (a2<=0 || a2>=9)||(b2<=0 || b2>=9))
    {
        std::cout<<"Enter wrong coordinates, try again"<<std::endl;
    }
    else
        Knight(a1,b1,a2,b2);
    return 0;
}
int coordinates(int x1, int y1, int x2, int y2)
{
    if ((x1>0 && y1>0) && (x2>0&&y2>0) || (x1>0 && y1<0) && (x2>0&&y2<0)\
    ||  (x1<0 && y1<0) && (x2<0&&y2<0) || (x1<0 && y1>0) && (x2<0&&y2>0))
    {
        std::cout<<"YES"<<std::endl;
    }
    else
        std::cout<<"NO"<<std::endl;
    return 0;
}
int main()
{
    std::string number;
    std::string sub_number1;
    std::cout<<"Enter number of a exercise (1 or 2) "<<std::endl;
    while((number!="1") && (number !="2"))
    {
        std::cin>>number;
        if (number=="1"||number=="2")
            break;
        else
        {
            std::cout<<"Enter indicated numbers (not a letter or another numbers)"<<std::endl;
        }
    }
    std::cout<<"Enter number of a exercise (1, 2, 3, 4 or 5)"<<std::endl;
    while((sub_number1!="1") && (sub_number1 !="2") && (sub_number1 != "3") && (sub_number1 != "4") && (sub_number1 != "5"))
    {
        std::cin >> sub_number1;
        if (sub_number1 == "1" || sub_number1 == "2" || sub_number1 == "3" || sub_number1 == "4" || sub_number1 == "5")
            break;
        else
        {
            std::cout << "Enter indicated numbers (not a letter or another numbers)" << std::endl;
        }
    }
    int Number1 = std::stoi(number);
    int Number2 = std::stoi(sub_number1);
    switch (Number1)
    {
        case (1):
        {
            switch (Number2)
            {
                case(1):
                    int year;
                    std::cout<<"Enter the CE year (but not 0) "<<std::endl;
                    std::cin>>year;
                    if (year<=0)
                        std::cout<<"Enter CE (Common Era) year (but not 0)";
                    else
                    {
                        if ((year%400==0) || ((year %4==0) && (year%100!=0)))
                            std::cout<<"Its leap year"<<std::endl;
                        else
                            std::cout<<"It isn't leap year"<<std::endl;
                    }
                    break;
                case(2):
                    chess_rules1();
                    break;
                case(3):
                    chess_rules2();
                    break;
                case(4):
                    chess_rules3();
                    break;
                case(5):
                    chess_rules4();
                    break;
            }
            break;
        }

        case(2):
        {
            switch (Number2)
            {
                case(1):
                {
                    int a1,b1,c1;
                    std::cout<<"Enter 3 numbers"<<std::endl;
                    std::cin>>a1>>b1>>c1;
                    if (std::cin.good())
                        std::cout<<"the highest number is "<<std::max({a1, b1, c1});
                    else
                        std::cout<<"Enter wrong number, try again";
                    break;
                }
                case(2):
                {
                    int a2,b2,c2;
                    std::cout<<"Enter 3 numbers"<<std::endl;
                    std::cin>>a2>>b2>>c2;
                    if (a2 > b2)
                        std::swap(a2, b2);
                    if (b2 > c2)
                        std::swap(b2, c2);
                    if (a2 > b2)
                        std::swap(a2, b2);
                    std::cout<<a2<<" "<<b2<<" "<<c2;
                    break;
                }
                case(3):
                {
                    int a3, b3, c3;
                    std::cout << "Enter 3 numbers" << std::endl;
                    std::cin >> a3 >> b3 >> c3;
                    if (std::cin.fail())
                        std::cout << "Enter wrong number, try again";
                    else
                    {
                        if (a3==b3 && b3==c3 && a3==c3)
                            std::cout<<"3"<<std::endl;
                        if ((a3==b3 && b3==c3) || (b3==c3 && a3==c3) || (a3==c3 && a3==b3))
                            std::cout<<"2"<<std::endl;
                        else
                            std::cout<<"1"<<std::endl;
                    }
                    break;
                }
                case(4):
                {
                    int a4, b4, c4;
                    std::cout << "Enter 3 numbers" << std::endl;
                    std::cin >> a4 >> b4 >> c4;
                    if (std::cin.fail())
                        std::cout << "Enter wrong number, try again";
                    else
                    {
                        if ((a4%2==0 || b4%2==0 || c4%2==0)&&(a4%2!=0||b4%2!=0||c4%2!=0))
                            std::cout<<"YES"<<std::endl;
                        else
                            std::cout<<"NO"<<std::endl;
                        break;
                    }
                    break;
                }
                case(5):
                {
                    int a5, b5, c5, d5;
                    std::cout << "Enter 2 numbers - 1st coordinates" << std::endl;
                    std::cin >> a5 >> b5;
                    std::cout << "Enter 2 numbers - 2nd coordinates" << std::endl;
                    std::cin >> c5 >> d5;
                    if (a5==0||b5==0||c5==0||d5==0)
                        std::cout << "Enter wrong number, try again";
                    else
                    {
                        coordinates(a5,b5,c5,d5);
                    }
                    break;
                }
            }
            break;
        }
    }
}