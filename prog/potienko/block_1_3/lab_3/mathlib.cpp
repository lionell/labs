#include <cmath>
#include "mathlib.h"

//Обчислення факторіалу
long long Factorial(long long n) {
	long long result = 1l;
	for (int i = 2; i <= n; ++i) result *= i;
	return result;
}

//Перевірка на належність x проміжку (-1, 1)
bool F_check(double x) {
	return ((x > lrange) && (x < rrange));
}

//Обчислення значення функції за формулою
double F_lib(double x, int m) {
	return (double(Factorial(m)) / pow(1 - x, m + 1));
}

//Обчислення значення функції через суму
double F_sum(double x, int m, int& n) {
	n = 0;
	double result = 0.0;
	long long q = Factorial(m);
	double p = 1.0;
	double a = q * p;
	while (fabs(a) > precision) {
		result += a;
		n++;
		q = (q / n) * (m + n);
		p *= x;
		a = q * p;
	}
	return result;
}
