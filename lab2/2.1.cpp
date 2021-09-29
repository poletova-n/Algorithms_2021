#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout<<"enter three numbers"<<endl;
    cin >> a >> b >> c;
    if (cin.peek() != '\n')
    cout<<"enter THREE NUMBERS!!";
    else
        cout<<max(max(a,b),c);
}
