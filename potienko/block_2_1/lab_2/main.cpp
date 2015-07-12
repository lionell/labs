//
// Created by lionell on 3/15/15.
//

#include <iostream>

#include "iolib.h"
#include "Point.h"
#include "ContourFabric.h"

using namespace std;

int main() {
    cout << "Enter a: ";
    double a = read_positive_double();
    Contour* contour = ContourFabric::create(a);
    string user_answer = "";
    do {
        cout << "Enter x: ";
        double x = read_double();
        cout << "Enter y: ";
        double y = read_double();
        Point* user_point = new Point(x, y);
        Position relative_position = contour->where(user_point);
        double distance = contour->distance_to(user_point);
        print_relative_position(relative_position);
        print_relative_distance(distance, relative_position);
        delete user_point;
        cout << "Do you want to continue(yes/no)? ";
        cin >> user_answer;
    } while (user_answer == "yes");
    delete contour;
    return 0;
}