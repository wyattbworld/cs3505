#include "point.h"
#include <iostream>
using namespace std;

int main() {
    Point myPt(2.0, 3.0);
    Point otherPt;
    Point scaledPt = myPt * 3.0;
    cout << "x " << scaledPt.get_x() << endl;

    cout << myPt << endl;
    Point* newPt = new Point(4,5);
    delete newPt;
}
