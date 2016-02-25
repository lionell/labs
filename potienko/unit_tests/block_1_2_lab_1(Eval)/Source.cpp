#include <iostream>
#include <string>
#include "table.h"

using namespace std;

const double precision = 1e-12;

#pragma region Library

//Обчислення результату за формулою
double Eval(double x) {
	return (1.0f / (sin(1.0f / 5.0f) - log(x) / log(3.0f)));
}

#pragma endregion

struct Test {
	double x;
	double result;
	Test(double _x = 0.0, double _result = 0.0) {
		x = _x;
		result = _result;
	}
};

const int testCount = 10;
Test tests[] = {
	Test(1.0, 5.03348958591553),
	Test(2.0, -2.31342026743146),
	Test(3.33, -1.11566895275845),
	Test(5.5, -0.739065947354172),
	Test(4.7, -0.826458065618993),
	Test(0.55, 1.34617764741718),
	Test(1e-5, 0.0936488693626361),
	Test(7e-2, 0.381791291320016),
	Test(3e-5, 0.103325152937236),
	Test(2e-1, 0.601090562133382)
};

int main(int argv, char** argc) {
	cout << "Welcome to Unit Tests!" << endl;
	string** data = new string*[testCount];
	for (int i = 0; i < testCount; ++i) data[i] = new string[colsCount];
	for (int i = 0; i < testCount; ++i) {
		data[i][0] = to_string(i);
		data[i][1] = to_string(tests[i].x);
		double result = Eval(tests[i].x);
		data[i][2] = to_string(result);
		data[i][3] = to_string(tests[i].result);
		data[i][4] = (fabs(tests[i].result - result) < precision) ? "OK" : "Fail";
	}
	DrawTable(data, testCount);
	delete[] data;
	system("pause");
	return 0;
}