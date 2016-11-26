//
// Created by lionell on 3/21/15.
//

#include "Segment.h"
#include "share.h"
#include <algorithm>

Segment::Segment(Point *_a, Point *_b) {
    a = _a;
    b = _b;
}

Segment::~Segment() {
    delete a;
    delete b;
}

//<editor-fold desc="Get/Set methods">
Point* Segment::get_a() {
    return a;
}

Point* Segment::get_b() {
    return b;
}
//</editor-fold>

bool Segment::has(Point* point) {
    return (fabs((a->distance_to(point) + b->distance_to(point) - a->distance_to(b))) < EPS);
}

double Segment::evaluate(Point* point) {
    return ((point->get_x() - a->get_x())*(b->get_y() - a->get_y()) -
            (point->get_y() - a->get_y())*(b->get_x() - a->get_x()));
}

bool Segment::different_half_planes(Point* first, Point* second) {
    return (evaluate(first) * evaluate(second) < EPS);
}

bool Segment::intersects(Segment* segment) {
    if (has(segment->a)) return true;
    else if (has(segment->b)) return false;
    else return (different_half_planes(segment->a, segment->b) && segment->different_half_planes(a, b));
}

bool Segment::has_projection(Point* point) {
    double s1 = (a->get_x() - b->get_x()) * (point->get_x() - b->get_x()) +
            (a->get_y() - b->get_y()) * (point->get_y() - b->get_y());
    double s2 = (b->get_x() - a->get_x()) * (point->get_x() - a->get_x()) +
            (b->get_y() - a->get_y()) * (point->get_y() - a->get_y());
    return (s1 > EPS && s2 > EPS);
}

double Segment::distance_to(Point* point) {
    double result = std::min(a->distance_to(point), b->distance_to(point));
    if (has_projection(point)) {
        double A = (b->get_y() - a->get_y());
        double B = (a->get_x() - b->get_x());
        result = std::min(result, (fabs(evaluate(point)) / sqrt(A * A + B * B)));
    }
    return result;
}