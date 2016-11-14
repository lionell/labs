//
// Created by lionell on 3/21/15.
//

#include "iolib.h"
#include <iostream>
#include <limits>
#include "exceptions.h"

using namespace std;

double try_read_double() {
    double result = 0.0;
    cin >> result;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw(DoubleExpected());
    }
    else return result;
}

double read_double() {
    double result = 0.0;
    while (true) {
        try {
            result = try_read_double();
            break;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }
    }
    return result;
}

double try_read_positive_double() {
    double result = 0.0;
    try {
        result = try_read_double();
    }
    catch (...) {
        throw;
    }
    if (result <= EPS) throw(PositiveDoubleExpected());
    return result;
}

double read_positive_double() {
    double result = 0.0;
    while (true) {
        try {
            result = try_read_positive_double();
            break;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }
    }
    return result;
}

void print_relative_position(Position position) {
    cout << "Relative position: ";
    switch (position) {
        case inside:
            cout << "Inside";
            break;
        case on:
            cout << "On";
            break;
        case outside:
            cout << "Outside";
            break;
    }
    cout << endl;
}

void print_relative_distance(double distance, Position position) {
    cout << "Distance: " << ((position == inside) ? -distance : distance) << endl;
}