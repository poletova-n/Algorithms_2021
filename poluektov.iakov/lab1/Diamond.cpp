#include <cstdlib>
#include <iostream>
#include "Diamond.h"
#include "IncorrectTriangle.h"

Diamond::Diamond(double x1, double y1, double x2, double y2, double x3, double y3) {
    if((x1 == x2 && y1 == y3) || (x1 == x3 && y1 == y2)){
        center_.x_ = x1; center_.y_ = y1;
        setPoints(x2, y2, x3, y3);
    }
    if((x2 == x3 && y2 == y1) || (x2 == x1 && y2 == y3)){
        center_.x_ = x2; center_.y_ = y2;
        setPoints(x1, y1, x3, y3);
    }
    if((x3 == x1 && y3 == y2) || (x3 == x2 && y3 == y1)){
        center_.x_ = x3; center_.y_ = y3;
        setPoints(x2, y2, x1, y1);
    }
    else{}
}

bool Diamond::isTriangleCorrect(){
    return point1_.x_ - center_.x_ + point2_.y_ - center_.y_ > sqrt(pow(point1_.x_ - center_.x_, 2) + pow(point2_.y_ - center_.y_, 2));
};

void Diamond::setPoints(double x1, double y1, double x2, double y2) {
    if (point1_.x_ == center_.x_) {
        point1_.x_ = x1;point1_.y_ = y1;
        point2_.x_ = x2;point2_.y_ = y2;
    } else {
        point1_.x_ = x2; point1_.y_ = y2;
        point2_.x_ = x1; point2_.y_ = y1;
    }
    try {
        if(isTriangleCorrect()) throw IncorrectTriangle();
    }catch (std::exception &error){
        std::cerr << std::endl << error.what() << std::endl;
        exit(1);
    }
}

double Diamond::getArea() {
    return abs(point1_.x_ - center_.x_ )* abs(point2_.y_ - center_.y_) * 2;
}

rectangle_t Diamond::getFrameRect() {
    return rectangle_t{abs(point1_.x_ - center_.x_)*2, abs(point2_.y_ - center_.y_)*2, point_t{center_.x_, center_.y_}};
}

void Diamond::move(double x, double y) {
    center_.x_ += x; center_.y_ += y;
    point1_.x_ += x; point1_.y_ += y;
    point2_.x_ += x; point2_.y_ += y;
}

void Diamond::move(point_t newCenter) {
    double x = center_.x_ - newCenter.x_;
    double y = center_.y_ - newCenter.y_;
    move(x,y);
}

void Diamond::scale(double mult) {
    mult--;
    point1_.x_ += (point1_.x_ - center_.x_) * mult;
    point2_.y_ += (point2_.y_ - center_.y_) * mult;
}

void Diamond::print() {

}