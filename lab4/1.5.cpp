#include <iostream>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "You entered not the number!";

int main()
{
    try
    {
        int min = 10000000000;
        int minCount = 0;
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
            count++;
            if (input <= min && input != 0 && input > 0)
            {
                min = input;
                minCount = count;
            }
        }
        cout << "The minimum positive number at position " << minCount << " is " << min;
    }
    catch(const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}