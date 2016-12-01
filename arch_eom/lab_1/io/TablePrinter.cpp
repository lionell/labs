//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "TablePrinter.h"

void TablePrinter::add_column(const std::string &name, uint32_t width) {
    column_headers_.push_back(name);
    column_widths_.push_back(width);
}

void TablePrinter::print_header() {
    print_clear_separator();
    uint32_t total_width = 0;
    for (auto width : column_widths_) {
        total_width += width + 1;
    }
    total_width--;
    *out_ << "|" << std::setw(total_width) << center(title_, total_width) << "|" << std::endl;
    print_separator();
    *out_ << std::left;
    for (uint32_t i = 0; i < column_headers_.size(); ++i) {
        *out_ << "|" << std::setw(column_widths_[i]) << column_headers_[i];
    }
    *out_ << std::right;
    *out_ << "|" << std::endl;
    print_separator();
}

void TablePrinter::print_separator() {
    for (auto width : column_widths_) {
        *out_ << "+";
        for (uint32_t j = 0; j < width; ++j) {
            *out_ << "-";
        }
    }
    *out_ << "+" << std::endl;
}

void TablePrinter::print_clear_separator() {
    *out_ << "+";
    for (auto width : column_widths_) {
        for (uint32_t j = 0; j < width; ++j) {
            *out_ << "-";
        }
    }
    *out_ << std::string(column_headers_.size() - 1, '-');
    *out_ << "+" << std::endl;
}

void TablePrinter::print_footer() {
    print_separator();
}

TablePrinter &TablePrinter::operator<<(double d) {
    *out_ << "|" << std::setw(column_widths_[c_]) << std::scientific << d;
    c_++;
    if (c_ == column_headers_.size()) {
        c_ = 0;
        r_++;
        *out_ << "|" << std::endl;
    }
    return *this;
}

TablePrinter &TablePrinter::operator<<(int32_t i) {
    *out_ << "|" << std::setw(column_widths_[c_]) << i;
    c_++;
    if (c_ == column_headers_.size()) {
        c_ = 0;
        r_++;
        *out_ << "|" << std::endl;
    }
    return *this;
}

TablePrinter &TablePrinter::operator<<(uint32_t i) {
    *out_ << "|" << std::setw(column_widths_[c_]) << i;
    c_++;
    if (c_ == column_headers_.size()) {
        c_ = 0;
        r_++;
        *out_ << "|" << std::endl;
    }
    return *this;
}

TablePrinter &TablePrinter::operator<<(std::string s) {
    *out_ << "|" << std::setw(column_widths_[c_]) << s;
    c_++;
    if (c_ == column_headers_.size()) {
        c_ = 0;
        r_++;
        *out_ << "|" << std::endl;
    }
    return *this;
}

TablePrinter &TablePrinter::operator<<(std::ostream &(*func)(std::ostream &)) {
    for (uint32_t i = c_; i < column_headers_.size(); ++i) {
        *this << "";
    }
    return *this;
}

std::string TablePrinter::center(std::string s, uint32_t width) {
    uint32_t len = static_cast<uint32_t>(s.length());
    if(width < len) {
        return s;
    }

    int diff = width - len;
    int pad1 = diff/2;
    int pad2 = diff - pad1;
    return std::string(pad1, ' ') + s + std::string(pad2, ' ');
}
