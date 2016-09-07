//
// Created by lionell on 4/23/16.
//

#include "dict.h"
#include <fstream>

std::map<int, std::string> read_dict(std::string path) {
    std::string v;
    int k;
    std::map<int, std::string> res;

    std::ifstream in(path);

    while (in >> v >> k) {
        res[k] = v;
    }

    in.close();
    return res;
}