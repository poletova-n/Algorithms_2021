#ifndef ALGORITHMS_2021_SHAPE_H
#define ALGORITHMS_2021_SHAPE_H

#include "basic_types.h"

class Shape{

public:

    Shape() = default;

    virtual double getArea() = 0;

    virtual rectangle_t getFrameRect() = 0;

    virtual void move(double x, double y) = 0;

    virtual void move(point_t newCenter) = 0;

    virtual void scale(double mult) = 0;

    virtual void print() = 0;

    ~Shape() = default;
};

#endif //ALGORITHMS_2021_SHAPE_H

