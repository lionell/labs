//
// Created by lionell on 3/21/15.
//

#ifndef _LAB_3_CONTOURFABRIC_H_
#define _LAB_3_CONTOURFABRIC_H_

#include "share.h"
#include "Contour.h"

class ContourFabric {
private:

    //region _Contours declaration

    class _Contour_1: public Contour_1 {
    public:
        _Contour_1(double a): Contour_1(a) {}
    };
    class _Contour_2: public Contour_2 {
    public:
        _Contour_2(double a): Contour_2(a) {}
    };
    class _Contour_3: public Contour_3 {
    public:
        _Contour_3(double a): Contour_3(a) {}
    };
    class _Contour_4: public Contour_4 {
    public:
        _Contour_4(double a): Contour_4(a) {}
    };
    class _Contour_5: public Contour_5 {
    public:
        _Contour_5(double a): Contour_5(a) {}
    };
    class _Contour_6: public Contour_6 {
    public:
        _Contour_6(double a): Contour_6(a) {}
    };
    class _Contour_7: public Contour_7 {
    public:
        _Contour_7(double a): Contour_7(a) {}
    };
    class _Contour_8: public Contour_8 {
    public:
        _Contour_8(double a): Contour_8(a) {}
    };
    class _Contour_9: public Contour_9 {
    public:
        _Contour_9(double a): Contour_9(a) {}
    };
    class _Contour_10: public Contour_10 {
    public:
        _Contour_10(double a): Contour_10(a) {}
    };
    class _Contour_11: public Contour_11 {
    public:
        _Contour_11(double a): Contour_11(a) {}
    };
    class _Contour_12: public Contour_12 {
    public:
        _Contour_12(double a): Contour_12(a) {}
    };
    class _Contour_13: public Contour_13 {
    public:
        _Contour_13(double a): Contour_13(a) {}
    };
    class _Contour_14: public Contour_14 {
    public:
        _Contour_14(double a): Contour_14(a) {}
    };
    class _Contour_15: public Contour_15 {
    public:
        _Contour_15(double a): Contour_15(a) {}
    };
    class _Contour_16: public Contour_16 {
    public:
        _Contour_16(double a): Contour_16(a) {}
    };
    class _Contour_17: public Contour_17 {
    public:
        _Contour_17(double a): Contour_17(a) {}
    };
    class _Contour_18: public Contour_18 {
    public:
        _Contour_18(double a): Contour_18(a) {}
    };
    class _Contour_19: public Contour_19 {
    public:
        _Contour_19(double a): Contour_19(a) {}
    };
    class _Contour_20: public Contour_20 {
    public:
        _Contour_20(double a): Contour_20(a) {}
    };
    class _Contour_21: public Contour_21 {
    public:
        _Contour_21(double a): Contour_21(a) {}
    };
    class _Contour_22: public Contour_22 {
    public:
        _Contour_22(double a): Contour_22(a) {}
    };
    class _Contour_23: public Contour_23 {
    public:
        _Contour_23(double a): Contour_23(a) {}
    };
    class _Contour_24: public Contour_24 {
    public:
        _Contour_24(double a): Contour_24(a) {}
    };
    class _Contour_25: public Contour_25 {
    public:
        _Contour_25(double a): Contour_25(a) {}
    };
    class _Contour_26: public Contour_26 {
    public:
        _Contour_26(double a): Contour_26(a) {}
    };
    class _Contour_27: public Contour_27 {
    public:
        _Contour_27(double a): Contour_27(a) {}
    };
    class _Contour_28: public Contour_28 {
    public:
        _Contour_28(double a): Contour_28(a) {}
    };
    class _Contour_29: public Contour_29 {
    public:
        _Contour_29(double a): Contour_29(a) {}
    };
    class _Contour_30: public Contour_30 {
    public:
        _Contour_30(double a): Contour_30(a) {}
    };
    class _Contour_31: public Contour_31 {
    public:
        _Contour_31(double a): Contour_31(a) {}
    };
    class _Contour_32: public Contour_32 {
    public:
        _Contour_32(double a): Contour_32(a) {}
    };
    class _Contour_33: public Contour_33 {
    public:
        _Contour_33(double a): Contour_33(a) {}
    };
    class _Contour_34: public Contour_34 {
    public:
        _Contour_34(double a): Contour_34(a) {}
    };

    //endregion

public:
    static IContour* create(double a, int number) {
        IContour* result = nullptr;
        if (a > EPS) {
            switch(number) {
                case 1:
                    result = new _Contour_1(a);
                    break;
                case 2:
                    result = new _Contour_2(a);
                    break;
                case 3:
                    result = new _Contour_3(a);
                    break;
                case 4:
                    result = new _Contour_4(a);
                    break;
                case 5:
                    result = new _Contour_5(a);
                    break;
                case 6:
                    result = new _Contour_6(a);
                    break;
                case 7:
                    result = new _Contour_7(a);
                    break;
                case 8:
                    result = new _Contour_8(a);
                    break;
                case 9:
                    result = new _Contour_9(a);
                    break;
                case 10:
                    result = new _Contour_10(a);
                    break;
                case 11:
                    result = new _Contour_11(a);
                    break;
                case 12:
                    result = new _Contour_12(a);
                    break;
                case 13:
                    result = new _Contour_13(a);
                    break;
                case 14:
                    result = new _Contour_14(a);
                    break;
                case 15:
                    result = new _Contour_15(a);
                    break;
                case 16:
                    result = new _Contour_16(a);
                    break;
                case 17:
                    result = new _Contour_17(a);
                    break;
                case 18:
                    result = new _Contour_18(a);
                    break;
                case 19:
                    result = new _Contour_19(a);
                    break;
                case 20:
                    result = new _Contour_20(a);
                    break;
                case 21:
                    result = new _Contour_21(a);
                    break;
                case 22:
                    result = new _Contour_22(a);
                    break;
                case 23:
                    result = new _Contour_23(a);
                    break;
                case 24:
                    result = new _Contour_24(a);
                    break;
                case 25:
                    result = new _Contour_25(a);
                    break;
                case 26:
                    result = new _Contour_26(a);
                    break;
                case 27:
                    result = new _Contour_27(a);
                    break;
                case 28:
                    result = new _Contour_28(a);
                    break;
                case 29:
                    result = new _Contour_29(a);
                    break;
                case 30:
                    result = new _Contour_30(a);
                    break;
                case 31:
                    result = new _Contour_31(a);
                    break;
                case 32:
                    result = new _Contour_32(a);
                    break;
                case 33:
                    result = new _Contour_33(a);
                    break;
                case 34:
                    result = new _Contour_34(a);
                    break;
                default:
                    break;
            }
        }
        return result;
    }

};

#endif //_LAB_3_CONTOURFABRIC_H_
