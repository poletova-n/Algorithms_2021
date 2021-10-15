#include <iostream>
using namespace std;
int main()
{
    int x1,y1;
    cout << "Select a piece" << endl << "1-rook 2-bishop" << endl;
    int a;
    cin >> a;
    cout << "enter coordinates of selected piece" << endl;
    cin >> x1 >> y1;

    if (cin.peek() != '\n')
        cout << "wrong input";
    else
    if ((x1<=0 || x1>=9) || (y1<=0 || y1>=9))
        cout << "wrong input";
    else
    {
        switch(a)
        {
            case(1):
            {
                int x2=x1;
                int y2=1;
                for(;x2>=1 && x2<=8 && y2>=1 && y2<=8; y2++)
                    cout<<x2<<" "<<y2<<endl;
                x2=1;
                y2=y1;
                for(;x2>=1 && x2<=8 && y2>=1 && y2<=8; x2++)
                    cout<<x2<<" "<<y2<<endl;
            }
            case(2):
            {
                int x2=x1;
                int y2=y1;
                if ((x2==1&&y2==1)||(x2==1&&y2==8)||(x2==8&&y2==1)||(x2==8&&y2==8)) {
                    if ((x2 == 1 && y2 == 1) || (x2 == 8 && y2 == 8))
                    {
                        for(;x2>1 && x2<=8 && y2>1 && y2<=8;x2--,y2--);
                        for(;x2>=1 && x2<=8 && y2>=1 && y2<=8;x2++,y2++)
                            cout<<x2<<" "<<y2<<endl;
                    }
                    if ((x2==8&&y2==1)||(x2==1&&y2==8))
                    {
                        for(;x2>1 && x2<=8 && y2>=1 && y2<8;x2--,y2++);
                        for(;x2>=1 && x2<=8 && y2>=1 && y2<=8;x2++,y2--)
                            cout<<x2<<" "<<y2<<endl;
                    }
                }
                else
                {
                    for(;x2>1 && x2<=8 && y2>1 && y2<=8;x2--,y2--);
                    for(;x2>=1 && x2<=8 && y2>=1 && y2<=8;x2++,y2++)
                        cout<<x2<<" "<<y2<<endl;
                    x2=x1;
                    y2=y1;
                    for(;x2>1 && x2<=8 && y2>=1 && y2<8;x2--,y2++);
                    for(;x2>=1 && x2<=8 && y2>=1 && y2<=8;x2++,y2--)
                        cout<<x2<<" "<<y2<<endl;
            }

            }
        }
    }
}