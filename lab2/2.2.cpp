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
        cout << min(min(a, b), c)<<" ";
        cout << (a + b + c) - max(max(a, b), c) - min(min(a, b), c)<<" ";
        cout << max(max(a, b), c)<<" ";
    }
}
