

#include <iostream>
#include <string.h>
void substr(char* des, char* str, int l, int r);
int find(char* str, char c);
bool isNum(char c);
bool isSym(char c);
bool isUnsig(char* str);
bool isTerm(char* str);
bool isExp(char* str);
bool isFactor(char* str);

int main() {
    char s[] = "((123)*А+234)))))";
    std::cout << isExp(s) << std::endl;

    return 0;
}
char* substr(char* str, size_t l, size_t r) {

    char* des = new char[r - l + 1];
#pragma warning(suppress : 4996)
    strncpy(des, str + l, r - l + 1);
    des[r - l + 1] = '\0';
    return des;
}
int find(char* str, char c) {
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;
    return -1;
}

bool isNum(char c) { return c >= '0' && c <= '9'; }
bool isSym(char c) { return 'A' <= c && 'E' >= c; }

bool isId(char* c) { return isSym(*c); }
bool isUnsig(char* str) {
    if (*str == '\0')
        return true;
    bool k = isNum(*str);
    str++;
    return k && isUnsig(str);
}
bool isFactor(char* str) {
    bool k = false;
    int l = strlen(str);
    if (str[0] == '(' && str[l - 1] == ')') {
        char* s1 = substr(str, 1, l - 2);
        k = isExp(s1);
    }
    return isUnsig(str) || isId(str) || k;
}
bool isTerm(char* str) {
    bool k = false;
    int ind = find(str, '*');
    int l = strlen(str);
    if (ind != -1) {
        char* s1 = substr(str, 0, ind - 1);
        char* s2 = substr(str, ind + 1, l);
        k = isFactor(s2) && isTerm(s1);
    }
    return isFactor(str) || k;
}
bool isExp(char* str) {
    bool k[] = { false, false };
    char d[] = { '+', '-' };
    int l = strlen(str);
    const int LEN = 2;
    for (int i = 0; i < LEN; i++) {
        int ind = find(str, d[i]);
        if (ind != -1) {
            char* s1 = substr(str, 0, ind - 1);
            char* s2 = substr(str, ind + 1, l);
            k[i] = isTerm(s1) && isExp(s2);
        }
    }
    return isTerm(str) || k[0] || k[1];
}
