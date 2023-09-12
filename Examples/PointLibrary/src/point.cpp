#include "point.h"
#include <iostream>

using namespace std;

// Implement the methods prototyped in point.h
Point::Point() {}

Point::Point(double x, double inity) : x(x), y(inity) {}

Point::~Point() {}

double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}

// Operators
Point Point::operator*(double scaleFactor) {
	Point res(x*scaleFactor, y*scaleFactor);
	return res;
}

// This doesn't start with Point:: so it is not class code.
ostream& operator<<(ostream& output, Point pt) {
    output << "(" << pt.x << "," << pt.y << ")";
    return output;
}

