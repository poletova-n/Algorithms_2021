#include <iostream>
using namespace std;
const char* error_invalid_number = "Numbers cannot be a letter";

int main()
{
    int  a = 1, b = 32000, c = 0, c1 = 0; //a - number, b - variable to compare, c - count, c1 - count2
    try
    {
        cout << "enter a sequence of integers " << endl;
        while (a != 0)
        {
            cin >> a;

            if (cin.peek() != '\n')
            {
                throw error_invalid_number;
            }                                                                                                                                                                                                                                                                               
            else
            {
                if (a < b)
                {
                    c++;
                    b = a;
                }               
                else
                {
                    b = 32000;
                    if (c1 < c)
                    {
                        c1 = c;
                        b = 32000;
                        c = 1;
                    }
                    else
                    {
                        b = 32000;
                        c = 1;
                    }
                }
            }
        }
        cout << c1;
    }
    catch (const char* error)
    {
        cerr << endl << error << endl;
    }
}