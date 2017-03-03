#include "math.h"

#include <cmath>

double Sqr(double x) {
	return x * x;
}

double L2Norm(double *a, double *b, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += Sqr(a[i] - b[i]);
	}
	return sqrt(sum);
}

