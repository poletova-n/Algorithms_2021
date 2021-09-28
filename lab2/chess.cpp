#include <iostream>
using namespace std;
int main()
{
    int x1,y1,x2,y2;
    cout << "Select a piece" << endl << "1-rook 2-bishop 3-queen 4-knight" << endl;

    int a;
    cin >> a;

cout << "enter coordinates of selected piece" << endl;
cin >> x1 >> y1;
cout << "enter coordinates of another piece" << endl;
cin >> x2 >> y2;

    if (cin.peek() != '\n')
        cout << "enter CORRECT coordinates";
    else
    if ((x1<=0 || x1>=9) || (y1<=0 || y1>=9) || (x2<=0 || x2>=9)||(y2<=0 || y2>=9))
        cout << "enter CORRECT coordinates";
    else
    {
        switch(a)
        {
            case(1):
            {
                if (x1 == x2 || y1 == y2)
                    cout<<"rook took a piece";
                else
                    cout<<"rook did not take a piece";
            }
            case(2):
            {
                if (abs(x1 - x2) == abs(y1 - y2))
                    cout << "bishop took a piece";
                else
                    cout << "bishop did not take a piece";
            }
            case(3):
            {
                if ((x1 == x2 || y1 == y2) || (abs(x1 - x2) == abs(y1 - y2)))
                    cout << "queen took a piece";
                else
                    cout<<"queen did not take a piece";
            }
            case(4):
            {
                if (((abs(x1-x2)==1) && abs(y1-y2)==2) || (abs(x1-x2)==2 && abs(y1-y2)==1))
                    cout<<"knight took a piece";
                else
                    cout<<"knight did not take a piece";
            }
            }
        }
    }


