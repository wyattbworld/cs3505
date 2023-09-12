#ifndef POINT_H
#define POINT_H

#include <iostream>

// using namespace std;

class Point {
private:
    double x,y; // data member or instance variable   
public:
    Point();
    Point(double x, double inity);
    ~Point();
    double get_x();
    double get_y();

    // Operators
    Point operator*(double scaleFactor);
    friend std::ostream& operator<<(std::ostream& output, Point pt);
};

#endif // include guard for POINT_H
