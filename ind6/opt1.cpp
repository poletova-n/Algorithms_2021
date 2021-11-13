#include <iostream>
#include <string>

bool stringIsTrue(std::string str, int iteration);
bool signChar(std::string str);
bool multiplyChar(std::string str);

int main()
{
    std::string input;
    std::cout << "Enter term: ";
    std::cin >> input;
    std::cout << std::endl;
    std::cout << "Result: " <<(stringIsTrue(input, 0) ? "TRUE" : "FALSE");
    return 0;
}

bool stringIsTrue(std::string str, int iteration)
{
    bool sign = signChar(str);
    bool multiply = multiplyChar(str);
    if (((sign || multiply) || ((((str[iteration] >= 'a') && (str[iteration] <= 'e')) || ((str[iteration] >= '0') && (str[iteration] <= '9'))))))
    {
        if (iteration == str.length()-1)
        {
            return true;
        }
        return stringIsTrue(str, iteration+1);
    }
    else
    {
        return false;
    }
}

bool signChar(std::string str)
{
    bool ans = false;
    int termSign;
    for(int i = 0; i < str.length()-1; ++i)
    {
        if(!((str[i] >= '0') && (str[i] <= '9')) && !((str[i] == '*') || (str[i] == '+') || (str[i] == '-')))
        {
            return false;
        }
        else
        {
            termSign = str.length()-1;
        }
        for (int j = 0; j < termSign; j++) {
            if(((str[j] == '+') || (str[j] == '-') || (str[j] == '*')) && ((str[i] >= '0') && (str[i] <= '9')))
            {
                ans = true;
            }
        }
    }
    return ans;
}

bool multiplyChar(std::string str)
{
    bool ans = false;
    int termSign;
    for (int i = 0; i < str.length(); ++i)
    {
        if(!((str[i] >= '0') && (str[i] <= '9')) && !((str[i] == '*') || (str[i] == '+') || (str[i] == '-')))
        {
            return false;
        }
        else
        {
            termSign = str.length()-1;
        }
        for (int j = 0; j < termSign; j++) {
            if(((str[j] == '*') || (str[j] == '+') || (str[j] == '-')) && ((str[i] >= '0') && (str[i] <= '9')))
            {
                ans = true;
            }
        }
    }
    return ans;
}


