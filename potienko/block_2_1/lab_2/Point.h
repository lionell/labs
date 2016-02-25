//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_2_POINT_H_
#define _LAB_2_POINT_H_

class Point {
private:
    double x;
    double y;
public:
    Point(double _x, double _y);

    //<editor-fold desc="Get/Set methods">
    double get_x();
    double get_y();
    //</editor-fold>

    double distance_to(Point* point);
};

#endif //_LAB_2_POINT_H_
