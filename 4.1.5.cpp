#include <iostream>
using namespace std;
const char* error_invalid_number = "Numbers cannot be a letter";

int main()
{
    int  a = 1, b = 32767, c = 0, d = 0; //a - number, b - min, c - count, d - nom

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
            if ((b > a) and (a>0))
            {
                b = a;
                d = c;
            }
        }
        cout << "min: " << b << endl << "his nom: " << d << endl;;
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}
