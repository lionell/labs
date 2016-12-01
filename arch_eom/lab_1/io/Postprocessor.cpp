//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "Postprocessor.h"
#include "TablePrinter.h"

double Postprocessor::get_max_speed(std::vector<std::tuple<std::string, std::string, double>> data) {
    double max_speed = DBL_MIN_10_EXP;
    for (auto row : data) {
        max_speed = std::max(max_speed, std::get<2>(row));
    }
    return max_speed;
}

std::string Postprocessor::generate_bar(int length) {
    std::ostringstream ss;
    for (uint32_t i = 1; i <= 100; ++i) {
        ss << ((i <= length) ? "X" : " ");
    }
    return ss.str();
}

void Postprocessor::process(std::vector<std::tuple<std::string, std::string, double>> data,
                            std::ostream *out) {
    TablePrinter tp("STATISTICS", out);
    tp.add_column("OP", 3);
    tp.add_column("TYPE", 8);
    tp.add_column("SPEED", 15);
    tp.add_column("BAR", 100);
    tp.add_column("%", 4);
    tp.print_header();
    double max_speed = get_max_speed(data);
    std::string last_type = std::get<1>(data[0]);
    for (auto row : data) {
        std::string op, type;
        double speed = 0.;
        std::tie(op, type, speed) = row;
        uint32_t percentage = static_cast<uint32_t>(std::round(100. * speed / max_speed));
        if (type != last_type) {
            tp.print_footer();
        }
        tp << op << type << speed << generate_bar(percentage) << percentage;
        last_type = type;
    }
    tp.print_footer();
}
