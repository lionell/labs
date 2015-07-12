//
// Created by lionell on 4/4/15.
//

#include "testutils.h"
#include "Station.h"

void Test::initialize() {
    Wagon::count = 0;
    train = new Train();
    set_up();
}

void Test::finalize() {
    delete train;
}

bool Test::run() {
    std::cout << "Input train:" << std::endl;
    print(train);
    Train **trains_returned = Station::unload(train);
    std::cout << "Output trains:" << std::endl;
    for (int i = 0; i < 3; ++i) print(trains_returned[i]);
    std::cout << "Expected trains:" << std::endl;
    const char *wagon_type_names[3] = {"Tanks: ", "Fridges: ", "Open: "};
    for (int i = 0; i < 3; ++i) {
        std::cout << wagon_type_names[i] << "T ";
        for (int j = 0; j < trains[i].size(); ++j) std::cout << trains[i][j] << " ";
        std::cout << std::endl;
    }
    bool result = is_equal(trains_returned, trains);
    delete[] trains_returned;
    return result;
}

bool is_equal(Train **left, std::vector<int> right[3]) {
    return (left[0]->to_vector() == right[0] && left[1]->to_vector() == right[1] && left[2]->to_vector() == right[2]);
}