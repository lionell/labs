//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef CONFIG_TABLEPRINTER_H
#define CONFIG_TABLEPRINTER_H

#include <bits/stdc++.h>

namespace printer {
    class endl {
    };
}

class TablePrinter {
    std::ostream *out_;
    std::string title_;
    std::vector<std::string> column_headers_;
    std::vector<uint32_t> column_widths_;
    uint32_t c_;
    uint32_t r_;
public:
    TablePrinter(std::string title, std::ostream *out = &std::cout) : title_(title), out_(out), r_(0), c_(0) { }

    virtual ~TablePrinter() { };

    void add_column(const std::string &name, uint32_t column_width);

    void print_header();

    void print_separator();

    void print_clear_separator();

    void print_footer();

    TablePrinter &operator<<(double d);

    TablePrinter &operator<<(int32_t i);

    TablePrinter &operator<<(uint32_t i);

    TablePrinter &operator<<(std::string s);

    TablePrinter &operator<<(std::ostream &(*f)(std::ostream &));

private:
    std::string center(std::string s, uint32_t width);
};

#endif //CONFIG_TABLEPRINTER_H
