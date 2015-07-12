#include <iostream>
#include <string>
#include "table.h"

using namespace std;

string header[colsCount] = { "x", "m", "f_lib(x)", "f_sum(x)", "difference", "N_adds" };
int widths[colsCount];

void DrawSeparator() {
	for (int i = 0; i < colsCount; ++i) {
		cout << '+';
		for (int j = 0; j < widths[i]; ++j) cout << '-';
	}
	cout << '+' << endl;
}

void DrawTable(double** data, int rowsCount) {
	for (int i = 0; i < colsCount; ++i) {
		widths[i] = header[i].length() + spacesBetween;
	}
	DrawSeparator();
	for (int i = 0; i < colsCount; ++i) {
		cout << '|';
		cout.width(widths[i]);
		cout << left << header[i];
	}
	cout << '|' << endl;
	for (int i = 0; i < rowsCount; ++i) {
		DrawSeparator();
		for (int j = 0; j < colsCount; ++j) {
			cout << '|';
			cout.width(widths[j]);
			cout << data[i][j];
		}
		cout << '|' << endl;
	}
	DrawSeparator();
}