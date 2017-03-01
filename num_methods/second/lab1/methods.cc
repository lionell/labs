#include "methods.h"
#include <cmath>

Float Rectangle(Float a, Float b, Func f) {
	return (b - a)*(f(a + (b - a)/2));
}

int RectangleMinN(Float a, Float b, Float max2, Float err) {
	return static_cast<int>((b - a)*powl((b - a)*max2 / (24*err), 0.5)) + 1;
}

Float Trapezoid(Float a, Float b, Func f) {
	return (b - a)*(f(a) + f(b))/2;
}

int TrapezoidMinN(Float a, Float b, Float max2, Float err) {
	return static_cast<int>((b - a)*powl((b - a)*max2 / (12*err), 0.5)) + 1;
}

Float Simpson(Float a, Float b, Func f) {
	return (b - a)*(f(a) + 4*f(a + (b - a)/2) + f(b))/6;
}

int SimpsonMinN(Float a, Float b, Float max4, Float err) {
	return static_cast<int>((b - a)*powl((b - a)*max4 / (2880*err), 0.25)) + 1;
}

Float Calc(Float a, Float b, int n, Func f, Method m) {
	Float step = (b - a) / n;
	Float sum = 0;
	Float c = a, d = c + step;
	while (n--) {
		sum += m(c, d, f);
		c = d;
		d += step;
	}
	return sum;
}
