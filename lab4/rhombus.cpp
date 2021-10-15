#include <iostream>
using namespace std;
int main ()
{
    int N, empty;
    cout << "Enter rhombus' side length  " << endl;
    cin >> N;
    empty = N-1;
    if (cin.peek() != '\n' || N <= 0)
        cerr << "wrong input\n";
    else
        for (int a = 0; a < N; a++)
        {
            cout << endl;
            for (int b = 0; b < empty+1; b++)
                cout << " ";
            for (int b = 0; b <= a-1; b++)
                cout << "* ";

            empty--;
        }
    empty = 0;
    for (int a = N; a > -1; a--)
    {
        cout << endl;
        for (int b = 0; b < empty; b++)
            cout << " ";
        for (int b = 0;b < a;b++)
            cout << "* ";
        empty++;
            }
        }
