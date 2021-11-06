#include <iostream>
using namespace std;
const char* error_invalid_number = "Numbers cannot be a letter";

int main()
{
    int  a = 1, b = 0, c = 0, d =0; //a - number, b - summ, c - count, d - nom
   
    try
    {
        cout << "Enter numbers: " << endl;
        while (a != 0)
        {
            cin >> a;
            c++;
            if (cin.peek() != '\n')
            {
                throw error_invalid_number;
            }
           if (b<a)
           {
               b = a;
               d = c;
           }
        }
        cout << "max: " << b << endl << "his nom: " << d << endl;;
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}