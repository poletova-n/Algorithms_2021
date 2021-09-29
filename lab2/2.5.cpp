#include <iostream>
using namespace std;
int main()
{
    int x1,x2,y1,y2;
    cout << "enter coordinates of the first point" << endl;
    cin >> x1 >> y1;
    if (cin.peek() != '\n')
        cout << "wrong input";
    else
    {
    cout<<"enter coordinates of the second point"<<endl;
    cin >> x2 >> y2;
    if (cin.peek() != '\n')
        cout << "wrong input";
    else
        if ((x1>0 && y1>0) && (x2>0 && y2>0))
            cout<<"YES";
        else if ((x1<0 && y1<0) && (x2<0 && y2<0))
            cout<<"YES";
        else if ((x1>0 && y1<0) && (x2>0 && y2<0))
            cout<<"YES";
        else if ((x1<0 && y1>0) && (x2<0 && y2>0))
            cout<<"YES";
        else
            cout<<"NO";

    }
}