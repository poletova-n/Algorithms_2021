#include <iostream>
#include <string>

bool isSign(std::string& num);
bool afterSign(std::string& num);
bool isRealNum(std::string& num);
bool WhereIsE(std::string& num);

int main()
{
    std::string num;
    std::cin >> num;
    if ((num[0] == '+') or (num[0] == '-') or (num[0] <= '9') and (num[0] >= '0') )
    {
        num.erase(num.begin());
        std::cout << isRealNum(num);
    }
    else
    {
        std::cout << false;
    }
}

bool isSign(std::string& num)
{
    if (num[0] == '+' or num[0] == '-')
    {
        num.erase(num.begin());
        return afterSign(num);
    }
    else
    {
        return false;
    }
}
bool afterSign(std::string& num)
{
    int iter = 0;
    if (num[iter] <= '9' and num[iter] >= '0')
    {
        iter++;
        if (num.size() == 1)
        {
            return true;
        }
        else
        {
            num.erase(num.begin());
            return afterSign(num);
        }
    }
    else
    {
        return false;
    }
}
bool WhereIsE(std::string& num)
{
    int iter = 0;
    if (num[iter] <= '9' and num[iter] >= '0')
    {
        iter++;
        num.erase(num.begin());
        return WhereIsE(num);
    }
    else if (num[iter] == 'E' and num[iter+1] <= '9' and num[iter+1] >= '0' )
    {
        return true;
    }
    else if (num[iter] == 'E' and num[iter+1])
    {
        num.erase(num.begin());
        return isSign(num);
    }
    else
    {
        return false;
    }
}
bool isRealNum(std::string& num)
{
    int iter = 0;
    if (num[iter] <= '9' and num[iter] >= '0')
    {
        iter++;
        num.erase(num.begin());
        return isRealNum(num);
    }
    else if(num[iter] == '.' and num[iter+1] != 'E')
    {
        num.erase(num.begin());
        return WhereIsE(num);
    }
    else if (num[iter] == 'E')
    {
        num.erase(num.begin());
        return isSign(num);

    }
    else
    {
        return false;
    }
}

