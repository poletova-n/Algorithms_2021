#ifndef ALGORITHMS_2021_TRIANGLE_H
#define ALGORITHMS_2021_TRIANGLE_H

#include <iostream>
#include "Point.h"

class Triangle{
public:

    Triangle();

    Triangle(const Point& a,const Point& b,const Point& c);

    Triangle(Triangle const &triangle);

    void setA(const Point& a);

    void setB(const Point& b);

    void setC(const Point& c);

    Point getA();

    Point getB();

    Point getC();

    bool isTriangle();

    void move(double move);

    double getPerimeter();

    double getSquare();

    bool isEquals(Triangle &triangle);

    bool isEqualSquare(Triangle &triangle);

    friend std::ostream& operator<<(std::ostream& out, const Triangle& triangle);

private:
Point a_;
Point b_;
Point c_;
};
#endif //ALGORITHMS_2021_TRIANGLE_H
