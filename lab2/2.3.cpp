#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "enter three numbers" << endl;
    cin >> a >> b >> c;
    if (cin.peek() != '\n')
        cout << "enter THREE NUMBERS!!";
    else
    {
        if((a==b) && (b==c))
            cout<<"3 identical numbers";
        if((a!=b)&&(a!=c)&&(b!=c))
            cout<<"none";
        else
            cout<<"2 identical numbers";
    }
}