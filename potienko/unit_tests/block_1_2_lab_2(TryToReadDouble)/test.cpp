#include <iostream>
#include <string>
#include "table.h"

using namespace std;

string header[] = { "Test", "Input", "x", "Expected", "Result", "Expected", "Status" };
int widths[] = { 4, 15, 15, 15, 6, 8, 6 };

void DrawSeparator() {
	for (int i = 0; i < colsCount; ++i) {
		cout << '+';
		for (int j = 0; j < widths[i]; ++j) cout << '-';
	}
	cout << '+' << endl;
}

void DrawTable(string** data, int rowsCount) {
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
			cout << right << data[i][j];
		}
		cout << '|' << endl;
	}
	DrawSeparator();
}