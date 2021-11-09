#include <iostream>
#include <string>

bool isPattern(std::string input, char type);

std::string charToString(char &input);

std::string stringWithOut(std::string &input, int start);

std::string stringBefore(std::string &input, int stop);

std::string stringAfter(std::string &input, int start);

std::string stringWithOutBrackets(std::string &input);

int findChar(std::string &input, char charToFind);

bool hasBrackets(std::string &input);

int main()
{
    std::string input;
    getline(std::cin,input);
    std::cout << isPattern(input, 'e');
    return 0;
}

bool isPattern(std::string input, char type)
{
    if(input.empty()) return false;

    int pPose;
    int mPose;
    int zPose;
    std::string sWNB;

    switch (type) {
        case 'e':
            if (isPattern(input, 't')) return true;

            pPose = findChar(input, '+');

            if (isPattern(stringBefore(input, pPose), 't')
               && pPose != -1
               && isPattern(stringAfter(input, pPose), 'e')) return true;

            mPose = findChar(input, '-');

            if (isPattern(stringBefore(input, mPose), 't')
               && mPose != -1
               && isPattern(stringAfter(input, mPose), 'e')) return true;

            return false;
        case 't':

            if (isPattern(input, 'm')) return true;

            zPose = findChar(input, '*');

            if (isPattern(stringBefore(input, zPose), 'm')
               && zPose != -1
               && isPattern(stringAfter(input, zPose), 't')) return true;

            pPose = findChar(input, '+');

            sWNB = stringWithOutBrackets(input);

            if (isPattern(stringBefore(sWNB, pPose - 1), 'm')
               && pPose != -1
               && hasBrackets(input)
               && isPattern(stringAfter(sWNB, pPose - 1), 't')) return true;

            return false;
        case 'm':

            if(isPattern(input, 'f')) return true;

            if(isPattern(input, 'i')) return true;

            sWNB = stringWithOutBrackets(input);

            if(isPattern(sWNB , 'e') && hasBrackets(input)) return true;

            return false;
        case 'f':

            if(isPattern(input, 'n')) return true;

            if(isPattern(charToString(input[0]), 'n')
               && isPattern(stringWithOut(input, 0), 'f')) return true;

            return false;
        case 'i':

            return (input == "x" || input == "y" || input == "z");

        case 'n':

            return (input == "0" || input == "1");

        default:

            return false;
    }
}

std::string charToString(char &input)
{
    std::string ans;
    ans += input;
    return ans;
}

std::string stringWithOut(std::string &input, int start)
{
    std::string ans;
    for (int i = 0; i < input.size(); ++i) {
        if( i > start ) ans += input[i];
    }
    return ans;
}

std::string stringBefore(std::string &input, int stop)
{
    std::string ans;
    for (int i = 0; i < stop; ++i) {
        ans += input[i];
    }
    return ans;
}

std::string stringAfter(std::string &input, int start)
{
    std::string ans;
    start += 1;
    for (int i = start; i < input.size(); ++i) {
        ans += input[i];
    }
    return ans;
}

std::string stringWithOutBrackets(std::string &input)
{
    std::string ans;
    if(input.size() < 2) return ans;
    for (int i = 0; i < input.size() - 2; ++i) {
        ans += input[i+1];
    }
    return ans;
}

int findChar(std::string &input, char charToFind)
{
    int left = 0;
    int right = 0;
    for (int i = 0; i < input.size(); ++i) {
        if(input[i] == charToFind && left == right) return i;
        if(input[i] == '(') left++;
        if(input[i] == ')') right++;
    }
    return -1;
}

bool hasBrackets(std::string &input)
{
    return input[0] == '(' && input[input.size() - 1] == ')';
}