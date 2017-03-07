#include "math.h"

#include <cmath>

double L1Norm(double *a, double *b, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += std::abs(a[i] - b[i]);
	}
	return sum;
}

