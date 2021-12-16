#include<iostream>
#include<cmath>
#include<limits>

double whileResult(double y0,double y1,double y2,const double & absError);

double doWhileResult(double y0,double y1,double y2,const double & absError);

double forResult(double Y0,double Y1,double Y2,const double & absError);

int main()
{
    double y0, y1, y2, absError;

    std::cout << "Input Y0:";
    std::cin >> y0;
    std::cout << "Input Y1:";
    std::cin >> y1;
    std::cout << "Input Y2:";
    std::cin >> y2;
    std::cout << "Input eps:";
    std::cin >> absError;

    std::cout << "Result of the while loop: " << "\t" << whileResult( y0, y1, y2, absError) << std::endl;
    std::cout << "Result of the do..while loop: "<< "\t"  << doWhileResult( y0, y1, y2, absError) << std::endl;
    std::cout << "Result of the for loop: " << "\t" << forResult( y0, y1, y2, absError) << std::endl;

    return 0;
}

double whileResult(double y0,double y1,double y2,const double & absError){

    int n = 3;
    double y = ( 2.5 * cos(y1) + 1) / (n * sqrt(2 + y2*y2 + y0*y0));

    while (fabs(y-y2) > absError){

        ++n;
        y0=y1;
        y1=y2;
        y2=y;

        y *= ( 2.5 * cos(y1) + 1) / (n * sqrt(2 + y2*y2 + y0*y0));

    }

    return y;
}

double doWhileResult(double y0,double y1,double y2,const double & absError){

    int n = 3;
    double y = ( 2.5 * cos(y1) + 1) / (n * sqrt(2 + y2*y2 + y0*y0));

    if(fabs(y - y2) <= absError) return y;

    do {

        ++n;
        y0=y1;
        y1=y2;
        y2=y;

        y *= ( 2.5 * cos(y1) + 1) / (n * sqrt(2 + y2*y2 + y0*y0));

    }
    while (fabs(y - y2) > absError);

    return y;
}

double forResult(double y0,double y1,double y2,const double & absError){

    double y = ( 2.5 * cos(y1) + 1) / (3.0 * sqrt(2 + y2*y2 + y0*y0));

    for (int n = 4; fabs(y - y2) > absError; ++n){

        y0=y1;
        y1=y2;
        y2=y;

        y *= ( 2.5 * cos(y1) + 1) / (n * sqrt(2 + y2*y2 + y0*y0));

    }

    return y;
}