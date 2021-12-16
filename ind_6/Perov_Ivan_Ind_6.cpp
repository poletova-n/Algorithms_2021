#include <iostream>
#include <string>
using namespace std;
bool checkNumBefE(string& num);
bool checkNumAftE(string& num);
int check = 0;
int main()
{
    string inp;
    cin >> inp;
    if (((inp[0] == '+') or (inp[0] == '-')) and inp[1] == '.') 
    {
        inp.erase(inp.begin());
        inp.erase(inp.begin());
        cout << checkNumBefE(inp);
    }
    else if (inp[0] == '.')
    {
        inp.erase(inp.begin());
        cout << checkNumBefE(inp);
    }
    else
    {
        cout << false;
    }
}
bool checkNumBefE(string& inp)
{
    if (inp[0] <= '9' and inp[0] >= '0')
    {
        inp.erase(inp.begin());
        return checkNumBefE(inp);
    }
    else if (inp[0] == 'E' and (inp[1] == '-' or inp[1] == '+') )
    {
        inp.erase(inp.begin());
        inp.erase(inp.begin());
        return checkNumAftE(inp);
    }
    else if (inp[0] == 'E')
    {
        inp.erase(inp.begin());
        return checkNumAftE(inp);
    }
    else
    {
        return false;
    }
}

bool checkNumAftE(string& inp)
{
    if (inp[0] <= '9' and inp[0] >= '0')
    {
        inp.erase(inp.begin());
        check++;
        return checkNumAftE(inp);
    }
    else if (inp.empty() and check!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
