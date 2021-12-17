#include <iostream>
#include <string>

bool isSign(std::string& num);
bool WhereIsE(std::string& num);
bool realNum(std::string& num);
bool beforeSign(std::string& num);
bool afterSign(std::string& num);

int main()
{
    std::string num;
    std::cin >> num;
    if ((num[1] >= '0') and (num[0] <= '9') and (num[1] == 'E'))
    {
        std::cout << false;
    }
    else if ((((num[0] == '+') or (num[0] == '-')) or ((num[0] >= '0') and (num[0] <= '9')))) {
        num.erase(num.begin());
        std::cout << realNum(num);
    }
    else
    {
        std::cout << false;
    }
}

bool isSign(std::string& num)
{
    if ((num[0] == '+') or (num[0] == '-'))
    {
        num.erase(num.begin());
        return afterSign(num);
    }
    else
    {
        return afterSign(num);
    }
}

bool realNum(std::string& num)
{
    int iter = 0;
    int dot = 0;
    if ((num[iter] >= '0') and (num[iter] <= '9') )
    {
        iter++;
        num.erase(num.begin());
        return realNum(num);
    }
    if (num[iter] == '.')
    {
        dot++;
    }
    if ((num[iter] == '.') and (num[iter]!= 'E'))
    {
        num.erase(num.begin());
        return WhereIsE(num);
    }
    if (dot != 1)
    {
        return false;
    }
    else if ((num[iter] == 'E') and (num[iter+1] == '+' or num[iter+1] == '-'))
    {
        num.erase(num.begin());
        num.erase(num.begin());
        return afterSign(num);
    }
    else if (num[iter] == 'E')
    {
        num.erase(num.begin());
        return afterSign(num);
    }
    else
    {
        return false;
    }
}

bool WhereIsE(std::string& num)
{
    int iter = 0;
    if ((num[iter] >= '0') and (num[iter] <= '9'))
    {
        iter++;
        num.erase(num.begin());
        return WhereIsE(num);
    }
    else if (num[iter]== 'E')
    {
        num.erase(num.begin());
        return isSign(num);
    }
    else
    {
        return false;
    }
}

bool afterSign(std::string& num)
{
    int iter = 0;
    if ((num[iter] >= '0') and (num[iter]<= '9')) {
        if (num.length() == 1)
        {
            return true;
        }
        iter++;
        num.erase(num.begin());
        return afterSign(num);
    }
    else
    {
        return false;
    }
}
bool beforeSign(std::string& num)
{
    int iter = 0;
    if ((num[iter] >= '0') and (num[iter]<= '9'))
    {
        if (num.length() == 1)
        {
            return true;
        }
        iter++;
        num.erase(num.begin());
        return afterSign(num);

    }
    else if (num[iter] == '.')
    {
        return afterSign(num);
    }
    else
    {
        return false;
    }
}