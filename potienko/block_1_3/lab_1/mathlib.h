#ifndef _MATHLIB_H_
#define _MATHLIB_H_

const double precision = 1e-10;
const double lrange = -1.0;
const double rrange = 1.0;

bool F_check(double);
double F_lib(double, int);
double F_sum(double, int, int&);

#endif