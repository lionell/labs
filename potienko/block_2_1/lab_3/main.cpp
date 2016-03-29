#include "iolib.h"
#include "Point.h"
#include "ContourFabric.h"
#include <iostream>

using namespace std;

int main() {
    string user_answer = "";
    do {
        cout << "Choose contour number(1-34): ";
        int number = read_positive_integer();
        cout << "Enter a: ";
        double a = read_positive_double();
        IContour* contour = ContourFabric::create(a, number);
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
            cout << "Do you want to continue with this contour(yes/no)? ";
            cin >> user_answer;
        } while (user_answer == "yes");
        delete contour;
        cout << "Do you want to continue(yes/no)? ";
        cin >> user_answer;
    } while (user_answer == "yes");
    return 0;
}