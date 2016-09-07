//
// Created by lionell on 4/23/16.
//

#include "utils.h"

bool next_bit(std::ifstream &in) {
    char c;
    in >> c;
    return c - '0';
}