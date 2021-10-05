#include <iostream>
using namespace std;
int main ()
{
    {
        double a1,a2;
        int count=0;
        cout << "Enter elements (type 0 for quit program):\n";
        cin>>a1;
        if (a1==0)
            cerr<<"empty row, end of program\n";
        else
            while (a1!=0)
            {
                cin>>a2;
                if (cin.peek() != '\n')
                {
                    cerr<< "wrong input, try again\n";
                }
                else
                if (a2==0)
                {
                    cout << "amount of elements=" << count << "\n";
                    break;
                }
                else
                {
                    if (a1>a2)
                        count++;
                    a1=a2;
                }
            }
    }
}
