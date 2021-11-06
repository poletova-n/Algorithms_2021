#include <iostream>
using namespace std;
int main()
{
	int a, b, i, j;
    cout << "enter coordinates" << endl;
    cin >> a >> b;
    if (cin.peek() != '\n')
    {
        cout << "coordinate must be a number"<<endl;
    }
    else
    {
        if ((a < 1) || (a > 8))
        {
            cout << "coordinates must 1..8" << endl;
        }
        if ((b < 1) || (b > 8))
        {
            cout << "coordinates must 1..8" << endl;
        }
        for (int i = 1; i < 9; i++)
        {
            if (i != b)
            {
                cout << "(" << a << ";" << i << ")";
            }
            if (i != a)
            {
                cout << "(" << i << ";" << b << ")";
            }
        }
    }
}