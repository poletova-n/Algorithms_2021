#include <iostream>
#include "Triangle.h"

Triangle::Triangle() {
    this->a_ = {0,0};
    this->b_ = {0,0};
    this->c_ = {0,0};
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
}

Triangle::Triangle(const Triangle &triangle) {
    this->a_ = triangle.a_;
    this->b_ = triangle.b_;
    this->c_ = triangle.c_;
}

void Triangle::setA(const Point& a) {
    this->a_ = a;
}

void Triangle::setB(const Point& b) {
    this->b_ = b;
}

void Triangle::setC(const Point& c) {
    this->c_ = c;
}

Point Triangle::getA() {
    return this->a_;
}

Point Triangle::getB() {
    return this->b_;
}

Point Triangle::getC() {
    return this->c_;
}

bool Triangle::isTriangle() {
    return std::max(a_.getDistance(this->b_), std::max(a_.getDistance(this->c_), this->c_.getDistance(this->b_))) <
    (this->getPerimeter() - std::max(a_.getDistance(this->b_), std::max(a_.getDistance(this->c_), this->c_.getDistance(this->b_))));
}

void Triangle::move(double move) {
    this->a_.move(move);
    this->b_.move(move);
    this->c_.move(move);
}

double Triangle::getPerimeter() {
    return this->a_.getDistance(this->b_) + a_.getDistance(this->c_) + this->c_.getDistance(this->b_);
}

double Triangle::getSquare() {
    return sqrt(this->getPerimeter() * (this->getPerimeter() - a_.getDistance(this->b_)) *
    (this->getPerimeter() - a_.getDistance(this->c_)) * (this->getPerimeter() - b_.getDistance(this->c_)));
}

bool Triangle::isEquals(Triangle &triangle) {
    return triangle.getA().isEquals(this->a_) && triangle.getB().isEquals(this->b_) && triangle.getC().isEquals(this->c_);
}

bool Triangle::isEqualSquare(Triangle &triangle) {
    return this->getSquare() == triangle.getSquare();
}

std::ostream& operator<<(std::ostream& out, const Triangle& triangle){
    out << "a";
    return out;
}