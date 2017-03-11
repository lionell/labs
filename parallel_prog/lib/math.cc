#include "math.h"

#include <cmath>

double L1Norm(const std::vector<double> a, const std::vector<double> b) {
	double sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += std::abs(a[i] - b[i]);
	}
	return sum;
}
