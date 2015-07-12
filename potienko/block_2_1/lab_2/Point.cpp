//
// Created by lionell on 3/21/15.
//

#include "Point.h"
#include <cmath>

Point::Point(double _x = 0.0, double _y = 0.0) {
    x = _x;
    y = _y;
}

//<editor-fold desc="Get/Set methods">
double Point::get_x() {
    return x;
}

double Point::get_y() {
    return y;
}
//</editor-fold>

double Point::distance_to(Point* point) {
    return sqrt((x - point->x)*(x - point->x) + (y - point->y)*(y - point->y));
}