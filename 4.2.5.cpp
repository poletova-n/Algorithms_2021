#include <iostream>
using namespace std;
int main()
{
    int N, probel;
    cout << "enter N" << endl;
    cin >> N;

    if ((cin.peek() != '\n') || (N < 0) || (N == 0))
    {
        cout << "N must be a number >0 " << endl;
    }
    else
    {
        probel = N - 1; 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < probel; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < i + 1; j++)
            {
                cout << "* ";
            }

            cout << endl;
            probel--;

        }
        probel = 1;
        for (int i = N-1; i > 0; i--)
        {

            for (int j = 0; j < probel; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < i; j++)
            {
                cout << "* ";
            }
            cout << endl;
            probel++;

        }
    }
}
