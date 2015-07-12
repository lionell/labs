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

#pragma endregion

struct Test {
	long long n;
	long long result;
	Test(long long _n = 0, long long _result = 0) {
		n = _n;
		result = _result;
	}
};

const int testCount = 10;
Test tests[] = {
	Test(1, 1),
	Test(9, 362880),
	Test(5, 120),
	Test(3, 6),
	Test(7, 5040),
	Test(10, 3628800),
	Test(4, 24),
	Test(2, 2),
	Test(6, 720),
	Test(8, 40320)
};

int main(int argv, char** argc) {
	cout << "Welcome to Unit Tests!" << endl;
	string** data = new string*[testCount];
	for (int i = 0; i < testCount; ++i) data[i] = new string[colsCount];
	for (int i = 0; i < testCount; ++i) {
		data[i][0] = to_string(i);
		data[i][1] = to_string(tests[i].n);
		long long result = Factorial(tests[i].n);
		data[i][2] = to_string(result);
		data[i][3] = to_string(tests[i].result);
		data[i][4] = (tests[i].result == result) ? "OK" : "Fail";
	}
	DrawTable(data, testCount);
	delete[] data;
	system("pause");
	return 0;
}