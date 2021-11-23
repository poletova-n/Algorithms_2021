#include <iostream>
#include <math.h>

class Point {
private:
	double x_;
	double y_;
public:
	Point () {
		this->x_ = 0.0;
		this->y_ = 0.0;
	}
	
	Point (double x_, double y_) {
		this->x_ = x_;
		this->y_ = y_;
	}
	
	~Point () {
		
	}
	
	void setX (double x) {
		this->x_ = x;
	}
	
	void setY (double y) {
		this->y_ = y;
	}

	double getX () {
		return this->x_;
	}

	double getY () {
		return this->y_;
	}

	bool isEqual (Point pt) {
		return (this->x_ == pt.x_ && this->y_ == pt.y_);
	}

	double getDistance (Point pt) {
		double x_axis = std::pow(this->x_ - pt.x_, 2);
		double y_axis = std::pow(this->y_ - pt.y_, 2);
		return std::sqrt(x_axis + y_axis);
	}

	void move (double K) {
		this->x_ += K;
		this->y_ += K;
	}
};


class Triangle {
private:
	Point a_, b_, c_;
public:
	Triangle () {
		this->a_ = Point();
		this->b_ = Point();
		this->c_ = Point();
	}

	Triangle (double a_x, double a_y, double b_x, double b_y, double c_x, double c_y) {
		this->a_ = Point(a_x, a_y);
		this->b_ = Point(b_x, b_y);
		this->c_ = Point(c_x, c_y);
	}

	~Triangle() {}

	void setA (double a_x, double a_y) {
		this->a_.setX(a_x);
		this->a_.setY(a_y);
	}

	void setB (double b_x, double b_y) {
		this->b_.setX(b_x);
		this->b_.setY(b_y);
	}

	void setC (double c_x, double c_y) {
		this->c_.setX(c_x);
		this->c_.setY(c_y);
	}

	Point getA () {
		std::cout << this->a_.getX() << " " << this->a_.getY();
	}

	Point getB () {
		std::cout << this->b_.getX() << " " << this->b_.getY();
	}

	Point getC () {
		std::cout << this->c_.getX() << " " << this->c_.getY();
	}

	double getPerimeter () {
		double AB = this->a_.getDistance(this->b_);
		double BC = this->b_.getDistance(this->c_);
		double CA = this->c_.getDistance(this->a_);
		return AB + BC + CA;
	}

	bool isTriangle () {
		double AB = this->a_.getDistance(this->b_);
		double BC = this->b_.getDistance(this->c_);
		double CA = this->c_.getDistance(this->a_);
		double sum = AB + BC + CA;
		double maximal = std::max(std::max(AB, BC), CA);
		return (sum - maximal) > maximal;
	}

	void move (double K) {
		this->a_.setX(this->a_.getX() + K);
		this->a_.setY(this->a_.getY() + K);

		this->b_.setX(this->b_.getX() + K);
		this->b_.setY(this->b_.getY() + K);

		this->c_.setX(this->c_.getX() + K);
		this->c_.setY(this->c_.getY() + K);
	}

	double getSquare () {
		double AB = this->a_.getDistance(this->b_);
		double BC = this->b_.getDistance(this->c_);
		double CA = this->c_.getDistance(this->a_);
		double half_perimeter = this->getPerimeter() / 2.0;
		return std::sqrt(half_perimeter*(half_perimeter-AB)*(half_perimeter-BC)*(half_perimeter-CA));
	}

	bool isEqual (Triangle tr) {
		return this->a_.isEqual(tr.a_) &&
			   this->b_.isEqual(tr.b_) &&
			   this->c_.isEqual(tr.c_);
	}
};

bool isPointInCircle (Point pt, double radius, double centerX = 0, double centerY = 0) {
	return pt.getDistance(Point(centerX, centerY)) <= radius;
}

void input (Point pt) {
	double x;
	std::cin >> x;
	double y;
	std::cin >> y;
	pt.setX(x);
	pt.setY(y);
}

void output (Point pt) {
	std::cout << pt.getX() << " " << pt.getY();
}

void output (Triangle tr) {
	output(tr.getA());
	output(tr.getB());
	output(tr.getC());
}

bool isTrianglesEqual (Triangle tr_1, Triangle tr_2) {
	return tr_1.getSquare() == tr_2.getSquare();
}

int main () {
	return 0;
}