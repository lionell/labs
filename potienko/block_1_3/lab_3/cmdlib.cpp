#include <iostream>
#include <string>
#include "cmdlib.h"

using namespace std;

void ReadName(int argv, char** argc) {
	string name = "";
	if ((argv > 2) && ((strcmp(argc[1], "-n") == 0) || (strcmp(argc[1], "--name") == 0))) {
		for (int i = 2; i < argv; ++i) {
			name += argc[i];
			if (argv - i > 1) name += " ";
		}
	}
	else {
		cout << "Enter your name: ";
		cin >> name;
	}
	cout << "Hello " << name << "!" << endl;
}

void WriteCopyright() {
	cout << "Copyright by Ruslan Sakevych(1st-year student, K-15 group) 2014-2015" << endl;
}