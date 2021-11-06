#include <iostream>
using namespace std;
int main()
{
    int N;
    cout << "enter N" << endl;
    cin >> N;

    if ((cin.peek() != '\n') || (N < 0) || (N == 0))
    {
        cout << "N must be a number >0 " << endl;
    }
    else
    {
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < N + 1; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
}
