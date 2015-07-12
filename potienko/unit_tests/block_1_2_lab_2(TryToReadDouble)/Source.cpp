#include <iostream>
#include <sstream>
#include <string>
#include "table.h"

using namespace std;

stringstream in;

#define cin in

const double precision = 1e-12;

#pragma region Library

//Намагаємся зчитати з клавіатури дійсне число, повертаємо True у випадку успіху, інакше False
bool TryToReadDouble(double& x)
{
	bool result = 0;
	cin >> x;
	if (cin.good() && (cin.get() == '\n')) result = 1;
	else {
		cin.clear();
		cin.sync();
	}
	return result;
}

#pragma endregion

struct Test {
	string input;
	bool result;
	double x;
	Test(string _input = "", bool _result = false, double _x = 0.0) {
		input = _input;
		result = _result;
		x = _x;
	}
};

const int testCount = 10;
Test tests[] = {
	Test("asdasdasd", false),
	Test("123", true, 123.0),
	Test("-1.233", true, -1.233),
	Test("ee", false),
	Test("1ee", false),
	Test("0.555", true, 0.555),
	Test("1e-3", true, 1e-3),
	Test("simple string", false),
	Test("-7e-2", true, -7e-2),
	Test("-3e-5", true, -3e-5)
};

int main(int argv, char** argc) {
	cout << "Welcome to Unit Tests!" << endl;
	string** data = new string*[testCount];
	for (int i = 0; i < testCount; ++i) data[i] = new string[colsCount];
	for (int i = 0; i < testCount; ++i) {
		data[i][0] = to_string(i);
		data[i][1] = tests[i].input;
		double x = 0.0;
		in.str("");
		in << tests[i].input << endl;
		bool result = TryToReadDouble(x);
		data[i][2] = to_string(x);
		data[i][3] = to_string(tests[i].x);
		data[i][4] = to_string(result);
		data[i][5] = to_string(tests[i].result);
		data[i][6] = ((result == tests[i].result) && (fabs(tests[i].x - x) < precision)) ? "OK" : "Fail";
	}
	DrawTable(data, testCount);
	delete[] data;
	system("pause");
	return 0;
}