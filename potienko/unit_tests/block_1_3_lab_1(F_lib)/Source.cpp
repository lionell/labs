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

//Обчислення значення функції за формулою
double F_lib(double x, int m) {
	return (double(Factorial(m)) / pow(1 - x, m + 1));
}

#pragma endregion

struct Test {
	double x;
	int m;
	double result;
	Test(double _x = 0.0, int _m = 0, double _result = 0.0) {
		x = _x;
		m = _m;
		result = _result;
	}
};

const int testCount = 10;
Test tests[] = {
	Test(0.1, 1, 1.234567901234),
	Test(-0.1, 2, 1.502629601803),
	Test(0.33, 1, 2.2276676319893),
	Test(-0.33, 7, 514.77495428896248),
	Test(0.71, 5, 201740.57701412801),
	Test(-0.99, 2, 0.2537878148602),
	Test(-1e-3, 5, 119.282513295089),
	Test(7e-5, 1, 1.0001400147013721),
	Test(3e-5, 4, 24.003600324022678),
	Test(2e-3, 6, 730.16112626988718)
};

int main(int argv, char** argc) {
	cout << "Welcome to Unit Tests!" << endl;
	string** data = new string*[testCount];
	for (int i = 0; i < testCount; ++i) data[i] = new string[colsCount];
	for (int i = 0; i < testCount; ++i) {
		data[i][0] = to_string(i);
		data[i][1] = to_string(tests[i].x);
		data[i][2] = to_string(tests[i].m);
		double result = F_lib(tests[i].x, tests[i].m);
		data[i][3] = to_string(result);
		data[i][4] = to_string(tests[i].result);
		data[i][5] = (fabs(tests[i].result - result) < precision) ? "OK" : "Fail";
	}
	DrawTable(data, testCount);
	delete[] data;
	system("pause");
	return 0;
}