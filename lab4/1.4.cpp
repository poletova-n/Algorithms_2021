#include <iostream>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "You entered not the number!";

int main()
{
    try
    {
        int max = 0;
        int maxCount = 0;
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
            if (input >= max)
            {
                max = input;
                maxCount = count;
            }
        }
        cout << "The maximum number at position " << maxCount << " is " << max;
    }
    catch(const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }
}