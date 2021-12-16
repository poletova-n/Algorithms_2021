#include <iostream>

double whileResult(int & m, int & n);

double doWhileResult(int & m, int & n);

double forResult(int & m, int & n);

int main(){

    int n, m;

    std::cout << "Input n:";
    std::cin >> n;
    std::cout << "Input m:";
    std::cin >> m;

    double j = 1;

    double x = n - (j / (m + 5) );

    std::cout << x << std::endl;

    double answer = 1;

    for (int i = 1; i <= n; ++i) {
        x = n - ( (double)i / (m + 5) );
        std::cout << x << " " << i << " " << (double)i / (m + 5.0) << std::endl  ;
        answer *= (x + 2.0 * m / n) / ((2 * n - (double)i) / (m + 4));
    }

    std::cout << answer;

    //std::cout << "Result of the while loop: " << "\t" << whileResult(m, n) << std::endl;
    //std::cout << "Result of the do..while loop: "<< "\t"  << doWhileResult(m, n) << std::endl;
    //std::cout << "Result of the for loop: " << "\t" << forResult(m, n) << std::endl;

    return 0;
}

double whileResult(int & m, int & n){

    double answer = 1, x;
    double i = m;
    double curM = m, curN = n;

    while(i <= n){
        x = (double) (curN - ((double)i / ((double)curM + 5.0) ));
        answer *= (x + 2.0 * curM / curN) / ((2 * curN - i) / (curM + 4));
        ++i;
    }

    return answer;
}

double doWhileResult(int & m, int & n){

    double answer = 1, x;
    double i = m;

    do{
        x = n - (i / (m + 5) );
        answer *= (x + 2.0 * m / n) / ((2 * n - i) / (m + 4));
        ++i;
    } while (i <= n);

    return answer;
}

double forResult(int & m, int & n){

    double answer = 1, x;

    for (int i = m; i <= n; ++i) {
        x = (double)n - ( (double)i / (m + 5) );
        answer *= (x + 2.0 * m / n) / ((2 * n - (double)i) / (m + 4));
    }

    return answer;
}

