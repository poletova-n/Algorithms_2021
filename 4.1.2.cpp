#include <iostream>
using namespace std;
const char* error_invalid_number = "Numbers cannot be a letter";

int main()
{
    int  a = -1, b = 0, c = -1; //a - number, b - summ, c - count, d - sr arifm
    double d;
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
            b += a;
            d = (double(b) / c);
        }
        cout << "sr arifm: " << d;
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}