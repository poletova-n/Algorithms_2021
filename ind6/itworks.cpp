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
    //std::cout << stringWithOutBrackets(input);
    std::cout << isPattern(input, 'e');
    return 0;
}

bool isPattern(std::string input, char type)
{
    if(input == "") return false;
    bool ans = false;
    bool ans1 = false;
    bool ans2 = false;
    bool ans3 = false;
    int pPose;
    int mPose;
    int zPose;
    std::string sWNB;
    switch (type) {
        case 'e':
            //std::cout << "e" << std::endl;

            pPose = findChar(input, '+');
            mPose = findChar(input, '-');

            //std::cout << stringBefore(input, pPose) << std::endl;
            //std::cout << stringAfter(input, pPose) << std::endl;

            //std::cout << mPose << " " << pPose << std::endl;

            ans1 = isPattern(input, 't');

            ans2 = (isPattern(stringBefore(input, pPose), 't')
                    && pPose != -1
                    && isPattern(stringAfter(input, pPose), 'e'));

            ans3 = (isPattern(stringBefore(input, mPose), 't')
                    && mPose != -1
                    && isPattern(stringAfter(input, mPose), 'e'));

            if(ans1 || ans2 || ans3) ans = true;
            break;
        case 't':
            //std::cout << "t " << input << std::endl;

            pPose = findChar(input, '+');
            zPose = findChar(input, '*');

            //std::cout << stringBefore(input, pPose) << std::endl;
            //std::cout << stringAfter(input, pPose) << std::endl;

            ans1 = isPattern(input, 'm');

            ans2 = (isPattern(stringBefore(input, zPose), 'm')
                    && zPose != -1
                    && isPattern(stringAfter(input, zPose), 't'));

            sWNB = stringWithOutBrackets(input);

            ans3 = (isPattern(stringBefore(sWNB, pPose - 1), 'm')
                    && pPose != -1
                    && hasBrackets(input)
                    && isPattern(stringAfter(sWNB, pPose - 1), 't'));


            if(ans1 || ans2 || ans3) ans = true;
            break;
        case 'm':
            //std::cout << "m " << input << std::endl;

            ans1 = isPattern(input, 'f');

            ans2 = isPattern(input, 'i');

            sWNB = stringWithOutBrackets(input);

            ans3 = (isPattern(sWNB , 'e') && hasBrackets(input));

            ans = ans1 || ans2 || ans3;
            break;
        case 'f':
            //std::cout << "f " << input << std::endl;

            ans1 = isPattern(input, 'n');

            ans2 = (isPattern(charToString(input[0]), 'n')
                    && isPattern(stringWithOut(input, 0), 'f'));

            if(ans1 || ans2) ans = true;
            break;
        case 'i':
            //std::cout << "i "<< input << std::endl;
            ans = (input == "x" || input == "y" || input == "z");
            //if(ans) ans = true;
            break;
        case 'n':
            //std::cout << "n " << input << std::endl;
            ans = (input == "0" || input == "1");
            //std::cout << ans << " " << "n" << std::endl;
            //if(ans1) ans = true;
            break;
    }
    //std::cout << ans << std::endl;
    return ans;
}

std::string charToString(char &input)
{
    std::string ans = "";
    ans += input;
    return ans;
}

std::string stringWithOut(std::string &input, int start)
{
    std::string ans = "";
    for (int i = 0; i < input.size(); ++i) {
        if( i > start ) ans += input[i];
    }
    return ans;
}

std::string stringBefore(std::string &input, int stop)
{
    std::string ans = "";
    for (int i = 0; i < stop; ++i) {
        ans += input[i];
    }
    return ans;
}

std::string stringAfter(std::string &input, int start)
{
    std::string ans = "";
    start += 1;
    for (int i = start; i < input.size(); ++i) {
        ans += input[i];
    }
    return ans;
}

std::string stringWithOutBrackets(std::string &input)
{
    std::string ans = "";
    if(input.size() < 2) return ans;
    for (int i = 0; i < input.size() - 2; ++i) {
        ans += input[i+1];
    }
    return ans;
}

int findChar(std::string &input, char charToFind)
{
    std::string ans = "";
    if(input.size() < 2) return ans;
    for (int i = 0; i < input.size() - 2; ++i) {
        ans += input[i+1];
    }
    return ans;
}

bool hasBrackets(std::string &input)
{
    return input[0] == '(' && input[input.size() - 1] == ')';
}