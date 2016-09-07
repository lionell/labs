//
// Created by lionell on 4/23/16.
//

#ifndef DECODE_DECODER_H
#define DECODE_DECODER_H

#include <fstream>
#include <vector>
#include "Hashes.h"

class Decoder {
    Hashes hash;
    int next(std::ifstream &in);
public:
    std::vector<int> decode(std::string path);
};


#endif //DECODE_DECODER_H
