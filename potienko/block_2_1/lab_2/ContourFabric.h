//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_2_CONTOURFABRIC_H_
#define _LAB_2_CONTOURFABRIC_H_

#include "share.h"
#include "Contour.h"

class ContourFabric {
private:
    class _Contour: public Contour {
    public:
        _Contour(double a): Contour(a) {}
    };
    ContourFabric() {}
public:
    static Contour* create(double a) {
        Contour* result = nullptr;
        if (a > EPS) result = new _Contour(a);
        return result;
    }

};

#endif //_LAB_2_CONTOURFABRIC_H_
