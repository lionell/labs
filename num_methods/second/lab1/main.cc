#include <iostream>
#include "methods.h"
#include <cmath>

using namespace std;

const Float kEps = 1e-8;

Float Sin(Float x) {
	return 10000*sinl(sqrtl(x));
}

int main() {
	int RectangleN = RectangleMinN(50, 200, 50, kEps);
	int TrapezoidN = TrapezoidMinN(50, 200, 50, kEps);
	int SimpsonN = SimpsonMinN(50, 200, 0.2, kEps);
	cout.precision(25);
	cout << "RectangleN: " << RectangleN << endl;
	cout << "TrapezoidN: " << TrapezoidN << endl;
	cout << "SimpsonN: " << SimpsonN << endl;
	cout << "Rectangle: " << Calc(50, 200, RectangleN, Sin, Rectangle) << endl;
	cout << "Trapezoid: " << Calc(50, 200, TrapezoidN, Sin, Trapezoid) << endl;
	cout << "Simpson: " << Calc(50, 200, SimpsonN, Sin, Simpson) << endl;

	return 0;
}
