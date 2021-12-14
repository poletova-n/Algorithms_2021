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












































//bool checkSign(string& num)
//{
//    if (num[0] == '+' or num[0] == '-')
//    {
//        num.erase(num.begin());
//        return next2Sign(num);
//    }
//    else
//    {
//        return false;
//    }
//}
//bool next2Sign(string& num)
//{
//    int iter = 0;
//    if (num[iter] <= '9' and num[iter] >= '0')
//    {
//        iter++;
//        if (num.size() == 1)
//        {
//            return true;
//        }
//        else
//        {
//            num.erase(num.begin());
//            return next2Sign(num);
//        }
//    }
//    else
//    {
//        return false;
//    }
//}
//bool serchForE(string& num)
//{
//    int iter = 0;
//    if (num[iter] <= '9' and num[iter] >= '0')
//    {
//        iter++;
//        num.erase(num.begin());
//        return serchForE(num);
//    }
//    else if (num[iter] == 'E' and num[iter + 1] <= '9' and num[iter + 1] >= '0')
//    {
//        return true;
//    }
//    else if (num[iter] == 'E' and num[iter + 1])
//    {
//        num.erase(num.begin());
//        return checkSign(num);
//    }
//    else
//    {
//        return false;
//    }
//}
//bool checkNum(string& num)
//{
//    int iter = 0;
//    if (num[iter] <= '9' and num[iter] >= '0')
//    {
//        iter++;
//        num.erase(num.begin());
//        return checkNum(num);
//    }
//    else if (num[iter] == '.' and num[iter + 1] != 'E')
//    {
//        num.erase(num.begin());
//        return serchForE(num);
//    }
//    else if (num[iter] == 'E')
//    {
//        num.erase(num.begin());
//        return checkSign(num);
//
//    }
//    else
//    {
//        return false;
//    }
//}
