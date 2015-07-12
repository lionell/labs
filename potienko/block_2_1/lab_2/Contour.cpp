//
// Created by lionell on 3/21/15.
//

#include "Contour.h"
#include "exceptions.h"
#include <algorithm>

Contour::Contour(double a) {
    segments[0] = new Segment(new Point(0, 0), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[4] = new Segment(new Point(-a, 0), new Point(0, 0));
}

Contour::~Contour() {
    for (int i = 0; i < 5; ++i) delete segments[i];
}

Position Contour::where(Point *point) {
    Point* point_somewhere = new Point(INF, INF);
    Segment* main_segment = new Segment(point, point_somewhere);
    for (int i = 0; i < 5; ++i) {
        if (segments[i]->has(point)) return on;
    }
    // Inside or Outside
    int intersections = 0;
    for (int i = 0; i < 5; ++i) {
        if (main_segment->intersects(segments[i])) intersections++;
    }
    return (intersections % 2 == 0) ? outside : inside;
}

double Contour::distance_to(Point* point) {
    double result = INF;
    for (int i = 0; i < 5; ++i) {
        result = std::min(result, segments[i]->distance_to(point));
    }
    return result;
}