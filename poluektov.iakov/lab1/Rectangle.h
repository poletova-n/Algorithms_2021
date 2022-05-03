//
// Created by Администратор on 12.04.2022.
//

#ifndef ALGORITHMS_2021_RECTANGLE_H
#define ALGORITHMS_2021_RECTANGLE_H


#include "Shape.h"
#include "basic_types.h"

class Rectangle : public Shape {
private:
    point_t point1_{};
    point_t point2_{};
public:

    explicit Rectangle(double left, double down, double right, double top);

    double getArea() override;

    rectangle_t getFrameRect() override;

    void move(double x, double y) override;

    void move(point_t newCenter) override;

    void scale(double mult) override;

    void print() override;

    ~Rectangle() = default;
};


#endif //ALGORITHMS_2021_RECTANGLE_H
