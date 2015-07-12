//
// Created by lionell on 3/21/15.
//

#include "debug.h"
#include <iostream>

using namespace std;

void print_point(Point* point) {
    cout << "(" << point->get_x() << ", " << point->get_y() << ")" << endl;
}

void print_segment(Segment* segment) {
    cout << "[";
    cout << "(" << segment->get_a()->get_x() << ", " << segment->get_a()->get_y() << ")";
    cout << " -> ";
    cout << "(" << segment->get_b()->get_x() << ", " << segment->get_b()->get_y() << ")";
    cout << "]";
    cout << endl;
}