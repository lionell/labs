//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_3_CONTOUR_H_
#define _LAB_3_CONTOUR_H_

#include "share.h"
#include "Point.h"
#include "Segment.h"

class IContour {
public:
    virtual Position where(Point *point) = 0;
    virtual double distance_to(Point* point) = 0;
    virtual ~IContour() {}
};

class Contour: public IContour {
protected:
    int segments_count;
    Segment **segments;
    Contour(int _segments_count = 0);
public:
    ~Contour();

    Position where(Point *point);
    double distance_to(Point* point);
};

class Contour_1: public Contour {
protected:
    Contour_1(double a = 0.0);
};

class Contour_2: public Contour {
protected:
    Contour_2(double a = 0.0);
};

class Contour_3: public Contour {
protected:
    Contour_3(double a = 0.0);
};

class Contour_4: public Contour {
protected:
    Contour_4(double a = 0.0);
};

class Contour_5: public Contour {
protected:
    Contour_5(double a = 0.0);
};

class Contour_6: public Contour {
protected:
    Contour_6(double a = 0.0);
};
class Contour_7: public Contour {
protected:
    Contour_7(double a = 0.0);
};

class Contour_8: public Contour {
protected:
    Contour_8(double a = 0.0);
};

class Contour_9: public Contour {
protected:
    Contour_9(double a = 0.0);
};

class Contour_10: public Contour {
protected:
    Contour_10(double a = 0.0);
};

class Contour_11: public Contour {
protected:
    Contour_11(double a = 0.0);
};

class Contour_12: public Contour {
protected:
    Contour_12(double a = 0.0);
};

class Contour_13: public Contour {
protected:
    Contour_13(double a = 0.0);
};

class Contour_14: public Contour {
protected:
    Contour_14(double a = 0.0);
};

class Contour_15: public Contour {
protected:
    Contour_15(double a = 0.0);
};

class Contour_16: public Contour {
protected:
    Contour_16(double a = 0.0);
};

class Contour_17: public Contour {
protected:
    Contour_17(double a = 0.0);
};

class Contour_18: public Contour {
protected:
    Contour_18(double a = 0.0);
};

class Contour_19: public Contour {
protected:
    Contour_19(double a = 0.0);
};

class Contour_20: public Contour {
protected:
    Contour_20(double a = 0.0);
};

class Contour_21: public Contour {
protected:
    Contour_21(double a = 0.0);
};

class Contour_22: public Contour {
protected:
    Contour_22(double a = 0.0);
};

class Contour_23: public Contour {
protected:
    Contour_23(double a = 0.0);
};

class Contour_24: public Contour {
protected:
    Contour_24(double a = 0.0);
};

class Contour_25: public Contour {
protected:
    Contour_25(double a = 0.0);
};

class Contour_26: public Contour {
protected:
    Contour_26(double a = 0.0);
};

class Contour_27: public Contour {
protected:
    Contour_27(double a = 0.0);
};

class Contour_28: public Contour {
protected:
    Contour_28(double a = 0.0);
};

class Contour_29: public Contour {
protected:
    Contour_29(double a = 0.0);
};

class Contour_30: public Contour {
protected:
    Contour_30(double a = 0.0);
};

class Contour_31: public Contour {
protected:
    Contour_31(double a = 0.0);
};

class Contour_32: public Contour {
protected:
    Contour_32(double a = 0.0);
};

class Contour_33: public Contour {
protected:
    Contour_33(double a = 0.0);
};

class Contour_34: public Contour {
protected:
    Contour_34(double a = 0.0);
};

#endif //_LAB_3_CONTOUR_H_
