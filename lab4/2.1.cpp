#include <iostream>
#include <string>
using namespace std;

const string ERROR_NOT_NUMBER = "You entered not the number!";
const string ERROR_LIMIT_BOARD = "You can't enter coordinates less than 1 or more than 8!";

int main()
{
    try {
        int x = 0, y = 0;
        cout << "Enter the coordinates of the chess piece: ";
        cin >> x >> y;
        if (cin.fail() || cin.peek() != 10)
        {
            throw ERROR_NOT_NUMBER;
        }
        if (x < 1 || y < 1 || x > 8 || y > 8)
        {
            throw ERROR_LIMIT_BOARD;
        }
        cout << "Positions under attack: ";
        cout << endl;
        for (int i = 1; i <= 8; ++i) {
            if(i != x)
            {
                cout << "[" <<i << " " << y << "]" <<" ";
            }
        }
        cout << endl;
        for (int i = 1; i <= 8; ++i)
        {
            if(i != y)
            {
                cout << "[" <<x << " " << i << "]" << " ";
            }
        }
    }
    catch(const string& error)
    {
        cerr << endl << error << endl;
        return -1;
    }

}