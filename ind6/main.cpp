#include <iostream>
#include <cctype>
bool isReal1(const char* a);
bool isReal2(const char* a, int& n);
bool isSign(const char* a, int& n);
bool isDigit(const char* a, int& n);
bool isInteger(const char* a, int& n) ;
bool isExponent(const char* a, int& n);
bool isMantiss(const char* a, int& n);
int main() {
    const char* str = "-488287E+1";
    std::cout << isReal1(str) << std::endl;
    std::cout << isReal1("-.74386518219223453245342654376574536543437648344E+561223623423425643263425634532453246542654367453645364562345234") << std::endl;
    std::cout << isReal1("-57578.7438651821928344E+5632419876") << std::endl;
    return 0;
}
bool isSign(const char* a, int& n) {
    if (a[n] == '+' || a[n] == '-') {
        n++;
        return true;
    }
    return false;
}
bool isDigit(const char* a, int& n) {
    if (std::isdigit(a[n])) {
        return true;
    }
    return false;
}
bool isInteger(const char* a, int& n) {
    bool r = isDigit(a, n);
    if (r && a[n] != '\0') {
        n++;
        isInteger(a, n);
    }
    return r;
}
bool isExponent(const char* a, int& n) {
    int N = n;
    if (a[N] == 'E') {
        N++;
        if (isSign(a, N) && isInteger(a, N)) {
            n = N;
            return true;
        }
        else if (isInteger(a, N)) {
            n = N;
            return true;
        }
    }
    return false;
}
bool isMantiss(const char* a, int& n) {
    int N = n;
    if (a[N] == '.') {
        N++;
        if (isInteger(a, N)) {
            n = N;
            return true;
        }
    }
    N = n;
    if (isInteger(a, N)) {
        n = N;
        if (a[N] == '.') {
            N++;
            if (isInteger(a, N)) {
                n = N;
                return true;
            }
            return false;
        }
    }
}
bool isReal2(const char* a, int& n)
{
    int N = n;
    if (isSign(a, N) && isMantiss(a, N) && isExponent(a, N))
    {
        n = N;
        return true;
    }
    return false;
}
bool isReal1(const char* a) {
    int n = 0;
    return ::isReal2(a, n) && a[n] == '\0';
}