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
        if ((a%2==0 || b%2==0 || c%2==0) && (a%2!=0 || b%2!=0 || c%2!=0) )
            cout<<"YES";
        else
            cout<<"NO";
    }
}