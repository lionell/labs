//
// Created by lionell on 4/23/16.
//

#ifndef DECODE_DECODE_H
#define DECODE_DECODE_H

#include <fstream>
#include <vector>

int next(std::ifstream &in);

std::vector<int> decode(std::string path);

#endif //DECODE_DECODE_H
