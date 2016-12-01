#include <iostream>
#include <string>
#include "table.h"

using namespace std;

const double precision = 1e-12;

#pragma region Library

//Обчислення факторіалу
long long Factorial(long long n) {
	long long result = 1l;
	for (int i = 2; i <= n; ++i) result *= i;
	return result;
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

#pragma endregion

struct Test {
	double x;
	int m;
	int n;
	double result;
	Test(double _x = 0.0, int _m = 0, int _n = 0, double _result = 0.0) {
		x = _x;
		m = _m;
		n = _n;
		result = _result;
	}
};

const int testCount = 10;
Test tests[] = {
	Test(0.1, 1, 14, 1.2345679012345678),
	Test(-0.1, 2, 15, 1.5026296018031551),
	Test(0.33, 1, 28, 2.2276676319893078),
	Test(-0.33, 7, 51, 514.77495428896248),
	Test(0.71, 5, 155, 201740.57701412801),
	Test(-0.99, 2, 4420, 0.25378781486026630),
	Test(-1e-3, 5, 6, 119.28251329508993),
	Test(7e-5, 1, 4, 1.0001400147013721),
	Test(3e-5, 4, 4, 24.003600324022678),
	Test(2e-3, 6, 7, 730.16112626988718)
};

int main(int argv, char** argc) {
	cout << "Welcome to Unit Tests!" << endl;
	string** data = new string*[testCount];
	for (int i = 0; i < testCount; ++i) data[i] = new string[colsCount];
	for (int i = 0; i < testCount; ++i) {
		data[i][0] = to_string(i);
		data[i][1] = to_string(tests[i].x);
		data[i][2] = to_string(tests[i].m);
		int n = 0;
		double result = F_sum(tests[i].x, tests[i].m, n);
		data[i][3] = to_string(n);
		data[i][4] = to_string(tests[i].n);
		data[i][5] = to_string(result);
		data[i][6] = to_string(tests[i].result);
		double tt = abs(tests[i].result - result);
		data[i][7] = ((tests[i].n == n) && (abs(tests[i].result - result)) < 1e-09) ? "OK" : "Fail";
	}
	DrawTable(data, testCount);
	delete[] data;
	system("pause");
	return 0;
}