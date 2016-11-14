//
// Created by lionell on 3/21/15.
//

#include "Contour.h"
#include "exceptions.h"
#include <algorithm>
#include <iostream>

//region Contour class definition

Contour::Contour(int _segments_count) {
    segments_count = _segments_count;
    segments = new Segment*[segments_count];
}

Contour::~Contour() {
    for (int i = 0; i < segments_count; ++i) delete segments[i];
    delete[] segments;
};

Position Contour::where(Point *point) {
    Point* point_somewhere = new Point(INF - 7, INF + 3);
    Segment* main_segment = new Segment(point, point_somewhere);
    for (int i = 0; i < segments_count; ++i) {
        if (segments[i]->has(point)) return on;
    }
    // Inside or Outside
    int intersections = 0;
    for (int i = 0; i < segments_count; ++i) {
        if (main_segment->intersects(segments[i])) intersections++;
    }
    return (intersections % 2 == 0) ? outside : inside;
}

double Contour::distance_to(Point* point) {
    double result = INF;
    for (int i = 0; i < segments_count; ++i) {
        result = std::min(result, segments[i]->distance_to(point));
    }
    return result;
}

//endregion

//region Contours definition

Contour_1::Contour_1(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(-a, a));
    segments[3] = new Segment(new Point(-a, a), new Point(0, 0));
}
Contour_2::Contour_2(double a): Contour(4) {
    segments[0] = new Segment(new Point(-a, -a), new Point(a, -a));
    segments[1] = new Segment(new Point(a, -a), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(-a, a));
    segments[3] = new Segment(new Point(-a, a), new Point(-a, -a));
}
Contour_3::Contour_3(double a): Contour(4) {
    segments[0] = new Segment(new Point(a, 0), new Point(a, 2 * a));
    segments[1] = new Segment(new Point(a, 2 * a), new Point(-a, 2 * a));
    segments[2] = new Segment(new Point(-a, 2 * a), new Point(-a, 0));
    segments[3] = new Segment(new Point(-a, 0), new Point(a, 0));
}
Contour_4::Contour_4(double a): Contour(4) {
    segments[0] = new Segment(new Point(-a, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(-a, a));
    segments[3] = new Segment(new Point(-a, a), new Point(-a, 0));
}
Contour_5::Contour_5(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, -a), new Point(a, -a));
    segments[1] = new Segment(new Point(a, -a), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(0, -a));
}
Contour_6::Contour_6(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, 2 * a));
    segments[2] = new Segment(new Point(a, 2 * a), new Point(0, 2 * a));
    segments[3] = new Segment(new Point(0, 2 * a), new Point(0, 0));
}
Contour_7::Contour_7(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(0, a));
    segments[2] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[3] = new Segment(new Point(-a, 0), new Point(0, -a));
}
Contour_8::Contour_8(double a): Contour(4) {
    segments[0] = new Segment(new Point(a, 0), new Point(2 * a, a));
    segments[1] = new Segment(new Point(2 * a, a), new Point(a, 2 * a));
    segments[2] = new Segment(new Point(a, 2 * a), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(a, 0));
}
Contour_9::Contour_9(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, a));
    segments[1] = new Segment(new Point(a, a), new Point(0, 2 * a));
    segments[2] = new Segment(new Point(0, 2 * a), new Point(-a, a));
    segments[3] = new Segment(new Point(-a, a), new Point(0, 0));
}
Contour_10::Contour_10(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(0, a));
    segments[2] = new Segment(new Point(0, a), new Point(0, 0));
}
Contour_11::Contour_11(double a): Contour(3) {
    segments[0] = new Segment(new Point(-a, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(0, a));
    segments[2] = new Segment(new Point(0, a), new Point(-a, 0));
}
Contour_12::Contour_12(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, 0));
}
Contour_13::Contour_13(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(0, a));
    segments[2] = new Segment(new Point(0, a), new Point(0, -a));
}
Contour_14::Contour_14(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, a));
    segments[1] = new Segment(new Point(a, a), new Point(-a, a));
    segments[2] = new Segment(new Point(-a, a), new Point(0, 0));
}
Contour_15::Contour_15(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, 0), new Point(2 * a, 0));
    segments[1] = new Segment(new Point(2 * a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, 0));
}
Contour_16::Contour_16(double a): Contour(3) {
    segments[0] = new Segment(new Point(0, a), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, 2 * a));
    segments[2] = new Segment(new Point(a, 2 * a), new Point(0, a));
}
Contour_17::Contour_17(double a): Contour(3) {
    segments[0] = new Segment(new Point(-a, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, 2 * a));
    segments[2] = new Segment(new Point(a, 2 * a), new Point(-a, 0));
}
Contour_18::Contour_18(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(0, -a));
}
Contour_19::Contour_19(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, 0), new Point(2 * a, 0));
    segments[1] = new Segment(new Point(2 * a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(0, 0));
}
Contour_20::Contour_20(double a): Contour(4) {
    segments[0] = new Segment(new Point(-2 * a, 0), new Point(2 * a, 0));
    segments[1] = new Segment(new Point(2 * a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(-a, a));
    segments[3] = new Segment(new Point(-a, a), new Point(-2 * a, 0));
}
Contour_21::Contour_21(double a): Contour(4) {
    segments[0] = new Segment(new Point(0, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(2 * a, a));
    segments[2] = new Segment(new Point(2 * a, a), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(0, 0));
}
Contour_22::Contour_22(double a): Contour(4) {
    segments[0] = new Segment(new Point(-a, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(2 * a, a));
    segments[2] = new Segment(new Point(2 * a, a), new Point(-2 * a, a));
    segments[3] = new Segment(new Point(-2 * a, a), new Point(-a, 0));
}
Contour_23::Contour_23(double a): Contour(5) {
    segments[0] = new Segment(new Point(0, 0), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[4] = new Segment(new Point(-a, 0), new Point(0, 0));
}
Contour_24::Contour_24(double a): Contour(5) {
    segments[0] = new Segment(new Point(-a, -a), new Point(a, -a));
    segments[1] = new Segment(new Point(a, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(-a, a));
    segments[4] = new Segment(new Point(-a, a), new Point(-a, -a));
}
Contour_25::Contour_25(double a): Contour(5) {
    segments[0] = new Segment(new Point(0, 0), new Point(2 * a, 0));
    segments[1] = new Segment(new Point(2 * a, 0), new Point(2 * a, a));
    segments[2] = new Segment(new Point(2 * a, a), new Point(a, 2 * a));
    segments[3] = new Segment(new Point(a, 2 * a), new Point(0, 2 * a));
    segments[4] = new Segment(new Point(0, 2 * a), new Point(0, 0));
}
Contour_26::Contour_26(double a): Contour(5) {
    segments[0] = new Segment(new Point(a, 0), new Point(2 * a, 0));
    segments[1] = new Segment(new Point(2 * a, 0), new Point(2 * a, 2 * a));
    segments[2] = new Segment(new Point(2 * a, 2 * a), new Point(0, 2 * a));
    segments[3] = new Segment(new Point(0, 2 * a), new Point(0, a));
    segments[4] = new Segment(new Point(0, a), new Point(a, 0));
}
Contour_27::Contour_27(double a): Contour(5) {
    segments[0] = new Segment(new Point(-a, -a), new Point(a, -a));
    segments[1] = new Segment(new Point(a, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(0, a));
    segments[3] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[4] = new Segment(new Point(-a, 0), new Point(-a, -a));
}
Contour_28::Contour_28(double a): Contour(5) {
    segments[0] = new Segment(new Point(-a, 0), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(a, a));
    segments[2] = new Segment(new Point(a, a), new Point(0, 2 * a));
    segments[3] = new Segment(new Point(0, 2 * a), new Point(-a, a));
    segments[4] = new Segment(new Point(-a, a), new Point(-a, 0));
}
Contour_29::Contour_29(double a): Contour(5) {
    segments[0] = new Segment(new Point(-a, 0), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(a, a));
    segments[3] = new Segment(new Point(a, a), new Point(0, a));
    segments[4] = new Segment(new Point(0, a), new Point(-a, 0));
}
Contour_30::Contour_30(double a): Contour(6) {
    segments[0] = new Segment(new Point(0, 0), new Point(0, a));
    segments[1] = new Segment(new Point(0, a), new Point(-a, a));
    segments[2] = new Segment(new Point(-a, a), new Point(-a, -a));
    segments[3] = new Segment(new Point(-a, -a), new Point(a, -a));
    segments[4] = new Segment(new Point(a, -a), new Point(a, 0));
    segments[5] = new Segment(new Point(a, 0), new Point(0, 0));
}
Contour_31::Contour_31(double a): Contour(6) {
    segments[0] = new Segment(new Point(0, 0), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, -a));
    segments[2] = new Segment(new Point(a, -a), new Point(a, a));
    segments[3] = new Segment(new Point(a, a), new Point(-a, a));
    segments[4] = new Segment(new Point(-a, a), new Point(-a, 0));
    segments[5] = new Segment(new Point(-a, 0), new Point(0, 0));
}
Contour_32::Contour_32(double a): Contour(6) {
    segments[0] = new Segment(new Point(-a, -a), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(a, a));
    segments[3] = new Segment(new Point(a, a), new Point(0, a));
    segments[4] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[5] = new Segment(new Point(-a, 0), new Point(-a, -a));
}
Contour_33::Contour_33(double a): Contour(6) {
    segments[0] = new Segment(new Point(0, 0), new Point(0, -a));
    segments[1] = new Segment(new Point(0, -a), new Point(a, 0));
    segments[2] = new Segment(new Point(a, 0), new Point(a, a));
    segments[3] = new Segment(new Point(a, a), new Point(0, a));
    segments[4] = new Segment(new Point(0, a), new Point(-a, 0));
    segments[5] = new Segment(new Point(-a, 0), new Point(0, 0));
}
Contour_34::Contour_34(double a): Contour(6) {
    segments[0] = new Segment(new Point(a, a), new Point(a, 0));
    segments[1] = new Segment(new Point(a, 0), new Point(2 * a, 0));
    segments[2] = new Segment(new Point(2 * a, 0), new Point(2 * a, 2 * a));
    segments[3] = new Segment(new Point(2 * a, 2 * a), new Point(0, 2 * a));
    segments[4] = new Segment(new Point(0, 2 * a), new Point(0, a));
    segments[5] = new Segment(new Point(0, a), new Point(a, a));
}

//endregion