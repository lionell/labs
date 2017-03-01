#ifndef METHODS_H_
#define METHODS_H_

#include <functional>
#include <mpi.h>

typedef long double Float;
const int kMpiFloat = MPI_LONG_DOUBLE;
typedef std::function<Float(Float)> Func;
typedef std::function<Float(Float, Float, Func)> Method;

Float Rectangle(Float a, Float b, Func f);
int RectangleMinN(Float a, Float b, Float max2, Float err);

Float Trapezoid(Float a, Float b, Func f);
int TrapezoidMinN(Float a, Float b, Float max2, Float err);

Float Simpson(Float a, Float b, Func f);
int SimpsonMinN(Float a, Float b, Float max4, Float err);

Float Calc(Float a, Float b, int n, Func f, Method m);

#endif  // METHODS_H_
