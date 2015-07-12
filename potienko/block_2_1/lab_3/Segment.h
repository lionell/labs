//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_3_SEGMENT_H_
#define _LAB_3_SEGMENT_H_

#include "Point.h"

class Segment {
private:
    Point *a;
    Point *b;
public:
    Segment(Point *_a = nullptr, Point *_b = nullptr);
    ~Segment();

    //<editor-fold desc="Get/Set methods">
    Point* get_a();
    Point* get_b();
    //</editor-fold>

    bool has(Point* point);
    double evaluate(Point* point);
    bool different_half_planes(Point* first, Point* second);
    bool intersects(Segment* segment);
    bool has_projection(Point* point);
    double distance_to(Point* point);
};

#endif //_LAB_3_SEGMENT_H_
