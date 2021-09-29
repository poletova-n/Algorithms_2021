#include <iostream>
using namespace std;

int main()
{
    int year;
    cout << "Enter a year(current era)" << endl;
    cin >> year;
    if (cin.peek() != '\n')
    {
        cout << "enter a NUMBER";
    }
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            cout << year << " is a leap year";
        }
        else
        {
            cout << year << " is not a leap year";
        }
    }
    return 0;
}
