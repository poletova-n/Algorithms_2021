#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "enter coordinates" << endl;
    cin >> a >> b;

    if ((cin.peek() != '\n') || ((a < 1) || (a > 8)) || ((b < 1) || (b > 8)))
    {
        cout << "coordinate must be a number 1..8" << endl;
    }
 
    else
    {
            for (int i = 1; i < 9; i++)
            {
                for (int j = 1; j < 9; j++)
                {
                    if (abs(a - i) == abs(b - j))
                    {
                        if (i != a and j != b)
                            cout << "(" << i << ";" << j << ")";
                    }
                }
            }
        
    }
}