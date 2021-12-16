#include <iostream>
#include "Point.h"

Point::Point() {
    this->x_ = 0;
    this->y_ = 0;
}

Point::Point(double x, double y) {
    this->x_ = x;
    this->y_ = y;
}

void Point::setX(double x) {
    this->x_ = x;
}

void Point::setY(double y) {
    this->y_ = y;
}

double Point::getX() const {
    return this->x_;
}

double Point::getY() const {
    return this->y_;
}

bool Point::isEquals(Point &point) const {
    return (point.getX() == this->x_) && (point.getY() == this->y_);
}

double Point::getDistance(Point &point) const {
    return sqrt(pow((point.getX() - this->x_),2)*pow((point.getY() - this->y_),2) );
}

bool Point::isPointInCircle(double radius) {
    return sqrt((this->x_,2)*pow(( this->y_),2) ) <= radius;
}

std::ostream& operator<<(std::ostream& out, const Point &point) {
    out << point.getX() << " " << point.getY();
    return out;
}

std::istream& operator>>(std::istream& cin, Point &point) {
    double x, y;
    cin >> x;
    cin >> y;
    point.setX(x); point.setY(y);
    return cin;
}

void Point::move(double moveDistance) {
    this->x_ = this->x_++;
    this->y_ = this->y_++;
}
