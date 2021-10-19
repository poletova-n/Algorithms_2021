#include <iostream>
#include <limits>
using namespace std;
int main ()
{
    double a,b,sum=0,count=0,average,posaverage,poscount=0, possum = 0,maxim,n = 1,nmax = 1,posmin,nposmin = 1;
    cout << "Enter numbers (type 0 for quit program):\n";
    cin>>a;
    sum += a;
    maxim = a;
    posmin = numeric_limits<double>::infinity(); //бесконечно большое число
    if (cin.peek() != '\n')
        cerr<< "wrong input, try again\n";
    else if (a==0)
        cerr<<"empty row, end of program\n";
    else
        while (a!=0)
        {
            cin>>b;
            if (cin.peek() != '\n')
            {
                cerr<< "wrong input, try again\n";
                break;
            }
            else
            {
                if(a<posmin && a>0)
                {
                    posmin = a;
                    nposmin = n;
                }
                if (a>0)
                {
                    possum+=a;
                    poscount++;
                }
                n++;
                a=b;
                sum+=a;
                count++;

                if (b>maxim)
                {
                    maxim =b;
                    nmax = n;
                }

                if(b<posmin && b>0)
                {
                    posmin = b;
                    nposmin = n;
                }
            }

            if (b==0)
            {
                average=(sum/count);
                posaverage=(possum/poscount);
                cout<<"sum = "<<sum<<endl<<"average = "<<average<<endl<<"positive average = "<<posaverage<<endl<<"max number = "<<maxim<<endl<<"max number is #"<<nmax<<endl<<"min positive number = "<<posmin<<endl<<"min positive number is #"<<nposmin<<endl;
                break;
            }
        }
}