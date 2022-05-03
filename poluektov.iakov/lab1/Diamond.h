//
// Created by Администратор on 12.04.2022.
//

#ifndef ALGORITHMS_2021_DIAMOND_H
#define ALGORITHMS_2021_DIAMOND_H


#include "basic_types.h"
#include "Shape.h"

class Diamond : Shape {
private:
    point_t point1_{};
    point_t point2_{};
    point_t center_{};

    void setPoints(double x1, double y1, double x2, double y2);

    bool isTriangleCorrect();

public:

    Diamond(double x1, double y1, double x2, double y2, double x3, double y3);

    double getArea() override;

    rectangle_t getFrameRect() override;

    void move(double x, double y) override;

    void move(point_t newCenter) override;

    void scale(double mult) override;

    void print() override;

    ~Diamond() = default;
};


#endif //ALGORITHMS_2021_DIAMOND_H
