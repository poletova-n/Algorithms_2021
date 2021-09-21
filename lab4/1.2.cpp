#include <iostream>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "You entered not the number!";

int main()
{
    try
    {
        int sum = 0;
        int count = 0;
        int input = 0;
        while (1)
        {
            cout << "Enter number:";
            cin >> input;
            if (cin.fail() || cin.peek() != 10) {
                throw ERROR_NOT_NUMBER;
            }
            if (input == 0)
            {
                break;
            }
            sum += input;
            count++;
        }
        cout << "The arithmetic mean of all numbers is: " << sum / count;
    }
    catch(const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}