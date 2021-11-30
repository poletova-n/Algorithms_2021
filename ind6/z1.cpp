#include <iostream>
#include <string>

using namespace std;

bool sign(string& str);

bool findE(string& str);

bool checkNumber(string& str);

bool afterSign(string& str);

int main() {
    string number;
    cin >> number;
    if ((((number[0] == '+') or (number[0] == '-')) or ((number[0] >= '0') and (number[0] <= '9')))) {
        number.erase(number.begin());
        cout << checkNumber(number);
    }
    else cout << false;
    return 0;
}

bool sign(string& str) {
    return ((str[0] == '+') or (str[0] == '-')) ? str.erase(str.begin()), afterSign(str) : false;
}

bool checkNumber(string& str) {
    int iterator = 0;
    if ((str[iterator] >= '0') and (str[iterator] <= '9') ) {
        iterator++;
        str.erase(str.begin());
        return checkNumber(str);
    }
    else if ((str[iterator] == '.') and (str[iterator + 1] != 'E')) {
        str.erase(str.begin());
        return findE(str);
    }
    else if (str[iterator] == 'E') {
        str.erase(str.begin());
        return sign(str);
    }
    else return false;
}

bool findE(string& str) {
    int iterator = 0;
    if ((str[iterator] >= '0') and (str[iterator] <= '9')) {
        iterator++;
        str.erase(str.begin());
        return findE(str);
    }
    else if (str[iterator] == 'E') {
        str.erase(str.begin());
        return sign(str);
    }
    else return false;
}

bool afterSign(string& str) {
    int iterator = 0;
    if ((str[iterator] >= '0') and (str[iterator] <= '9')) {
        if (str.length() == 1) return true;
        iterator++;
        str.erase(str.begin());
        return afterSign(str);
    }
    else return false;
}
