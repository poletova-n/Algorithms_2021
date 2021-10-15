#include <iostream>
using namespace std;
int main ()
{
    int N;
    cout<<"Enter square's side length "<<endl;
    cin>>N;
    if (cin.peek() != '\n' || N<=0)
        cerr<< "wrong input\n";
    else
        for (int a = 1; a < N+1; a++)
        {
            for (int b = 1; b < N+1; b++)
            {
                cout << "*";
            }
            cout <<endl;
        }
}