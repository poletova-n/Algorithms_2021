#include <iostream>

double whileResult(int & m);

double doWhileResult(int & m);

double forResult(int & m);

int main(){

    int m;

    std::cout << "Input m:";
    std::cin >> m;

    std::cout << "Result of the while loop: " << "\t" << whileResult(m) << std::endl;
    std::cout << "Result of the do..while loop: "<< "\t"  << doWhileResult(m) << std::endl;
    std::cout << "Result of the for loop: " << "\t" << forResult(m) << std::endl;

    return 0;
}

double whileResult(int & m){

    double answer = 1, x;
    double i = 1;

    while (i <= m) {
        x = 0.25 * (8.0 * i / m);
        answer *= (m / (i + 1.0) * x) / (m - i/m + 2.0);
        ++i;
    }

    return answer;
}

double doWhileResult(int & m){

    double answer = 1, x;
    double i = 1;

    do{
        x = 0.25 * (8.0 * i / m);
        answer *= (m / (i + 1.0) * x) / (m - i/m + 2.0);
        ++i;
    } while (i <= m);

    return answer;
}

double forResult(int & m){

    double answer = 1, x;

    for (int i = 1; i <= m; ++i) {
        x = 0.25 * (8.0 * i / m);
        answer *= (m / (i + 1.0) * x) / (m - (double)i/m + 2.0);
    }

    return answer;
}

