//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_2_CONTOUR_H_
#define _LAB_2_CONTOUR_H_

#include "share.h"
#include "Point.h"
#include "Segment.h"

class IContour {
public:
    virtual Position where(Point *point) = 0;
    virtual double distance_to(Point* point) = 0;
};

class Contour: public IContour {
private:
    Segment *segments[5];
protected:
    Contour(double a = 0.0);
public:
    ~Contour();
    Position where(Point *point);
    double distance_to(Point* point);
};

#endif //_LAB_2_CONTOUR_H_
