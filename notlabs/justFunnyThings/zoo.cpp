#include <iostream>
using std::cout;


int main(){

    int a = 2;

    int b = 4;

    float c = 4 / a++ - ++b / 2.0;

    std::cout << a << ' ' << b << ' ' << cout << std::endl;
};