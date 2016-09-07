//
// Created by lionell on 4/23/16.
//

#include "Dictionary.h"
#include <fstream>

void Dictionary::load(std::string path) {
    std::string v;
    int k;

    std::ifstream in(path);

    while (in >> v >> k) {
        dict[k] = v;
    }

    in.close();
}