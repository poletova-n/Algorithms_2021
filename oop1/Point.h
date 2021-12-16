#ifndef ALGORITHMS_2021_POINT_H
#define ALGORITHMS_2021_POINT_H

#include "Point.h"
#include <iostream>

class Point {
public:

    Point();

    Point(double x, double y);

    void setX(double x);

    void setY(double y);

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    bool isEquals(Point& point) const;

    double getDistance(Point &point) const;

    void move(double moveDistance);

    bool isPointInCircle(double radius);

    friend std::ostream& operator<<(std::ostream& out, const Point& point);

    friend std::istream& operator>>(std::istream& in, Point& point);

private:
    double x_;
    double y_;
};

#endif