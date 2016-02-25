//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "ops/Cpp.h"
#include "utils/Timer.h"
#include "io/TablePrinter.h"

const uint32_t LOWER_BOUND = 100000000;
const uint32_t UPPER_BOUND = 1000000000;
const double TIME_THRESHOLD = 2.;

std::ofstream out;

uint32_t search_n(void (*op)(uint32_t)) {
    uint32_t l = LOWER_BOUND;
    uint32_t r = UPPER_BOUND;
    while (l < r) {
        uint32_t m = l + ((r - l) >> 1);
        if (Timer::time_it(op, m) > TIME_THRESHOLD) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

void write_const(std::string name, uint32_t value) {
    out << "const uint32_t " << name << " = " << value << ";" << std::endl;
}

void process_const(std::string name, void (*op)(uint32_t)) {
    std::cerr << std::setw(10) << name << " ";
    write_const(name, search_n(op));
    std::cerr << std::endl;
}

void write_header() {
    out
    << "//\n"
    << "// Created by lionell on 21.02.16.\n"
    << "// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.\n"
    << "//\n"
    << "\n"
    << "#ifndef LAB_1_SETTINGS_H\n"
    << "#define LAB_1_SETTINGS_H\n"
    << "\n"
    << "#include <stdint.h>"
    << "\n"
    << "\n";
}

void write_footer() {
    out
    << "\n"
    << "#endif //LAB_1_SETTINGS_H";
}

void process() {
    std::cerr << "===PROCESSING===" << std::endl;
    // INT8
    process_const("INT8_ADD", Cpp::_add<int8_t>);
    process_const("INT8_SUB", Cpp::_sub<int8_t>);
    process_const("INT8_MUL", Cpp::_mul<int8_t>);
    process_const("INT8_DIV", Cpp::_div<int8_t>);
    process_const("INT8_MOD", Cpp::_mod<int8_t>);
    process_const("INT8_NEG", Cpp::_neg<int8_t>);
    process_const("INT8_AND", Cpp::_and<int8_t>);
    process_const("INT8_OR", Cpp::_or<int8_t>);
    process_const("INT8_XOR", Cpp::_xor<int8_t>);
    process_const("INT8_LSH", Cpp::_lsh<int8_t>);
    process_const("INT8_RSH", Cpp::_rsh<int8_t>);
    // UINT8
    process_const("UINT8_ADD", Cpp::_add<uint8_t>);
    process_const("UINT8_SUB", Cpp::_sub<uint8_t>);
    process_const("UINT8_MUL", Cpp::_mul<uint8_t>);
    process_const("UINT8_DIV", Cpp::_div<uint8_t>);
    process_const("UINT8_MOD", Cpp::_mod<uint8_t>);
    process_const("UINT8_NEG", Cpp::_neg<uint8_t>);
    process_const("UINT8_AND", Cpp::_and<uint8_t>);
    process_const("UINT8_OR", Cpp::_or<uint8_t>);
    process_const("UINT8_XOR", Cpp::_xor<uint8_t>);
    process_const("UINT8_LSH", Cpp::_lsh<uint8_t>);
    process_const("UINT8_RSH", Cpp::_rsh<uint8_t>);
    // INT16
    process_const("INT16_ADD", Cpp::_add<int16_t>);
    process_const("INT16_SUB", Cpp::_sub<int16_t>);
    process_const("INT16_MUL", Cpp::_mul<int16_t>);
    process_const("INT16_DIV", Cpp::_div<int16_t>);
    process_const("INT16_MOD", Cpp::_mod<int16_t>);
    process_const("INT16_NEG", Cpp::_neg<int16_t>);
    process_const("INT16_AND", Cpp::_and<int16_t>);
    process_const("INT16_OR", Cpp::_or<int16_t>);
    process_const("INT16_XOR", Cpp::_xor<int16_t>);
    process_const("INT16_LSH", Cpp::_lsh<int16_t>);
    process_const("INT16_RSH", Cpp::_rsh<int16_t>);
    // UINT16
    process_const("UINT16_ADD", Cpp::_add<uint16_t>);
    process_const("UINT16_SUB", Cpp::_sub<uint16_t>);
    process_const("UINT16_MUL", Cpp::_mul<uint16_t>);
    process_const("UINT16_DIV", Cpp::_div<uint16_t>);
    process_const("UINT16_MOD", Cpp::_mod<uint16_t>);
    process_const("UINT16_NEG", Cpp::_neg<uint16_t>);
    process_const("UINT16_AND", Cpp::_and<uint16_t>);
    process_const("UINT16_OR", Cpp::_or<uint16_t>);
    process_const("UINT16_XOR", Cpp::_xor<uint16_t>);
    process_const("UINT16_LSH", Cpp::_lsh<uint16_t>);
    process_const("UINT16_RSH", Cpp::_rsh<uint16_t>);
    // INT32
    process_const("INT32_ADD", Cpp::_add<int32_t>);
    process_const("INT32_SUB", Cpp::_sub<int32_t>);
    process_const("INT32_MUL", Cpp::_mul<int32_t>);
    process_const("INT32_DIV", Cpp::_div<int32_t>);
    process_const("INT32_MOD", Cpp::_mod<int32_t>);
    process_const("INT32_NEG", Cpp::_neg<int32_t>);
    process_const("INT32_AND", Cpp::_and<int32_t>);
    process_const("INT32_OR", Cpp::_or<int32_t>);
    process_const("INT32_XOR", Cpp::_xor<int32_t>);
    process_const("INT32_LSH", Cpp::_lsh<int32_t>);
    process_const("INT32_RSH", Cpp::_rsh<int32_t>);
    // UINT32
    process_const("UINT32_ADD", Cpp::_add<uint32_t>);
    process_const("UINT32_SUB", Cpp::_sub<uint32_t>);
    process_const("UINT32_MUL", Cpp::_mul<uint32_t>);
    process_const("UINT32_DIV", Cpp::_div<uint32_t>);
    process_const("UINT32_MOD", Cpp::_mod<uint32_t>);
    process_const("UINT32_NEG", Cpp::_neg<uint32_t>);
    process_const("UINT32_AND", Cpp::_and<uint32_t>);
    process_const("UINT32_OR", Cpp::_or<uint32_t>);
    process_const("UINT32_XOR", Cpp::_xor<uint32_t>);
    process_const("UINT32_LSH", Cpp::_lsh<uint32_t>);
    process_const("UINT32_RSH", Cpp::_rsh<uint32_t>);
    // INT64
    process_const("INT64_ADD", Cpp::_add<int64_t>);
    process_const("INT64_SUB", Cpp::_sub<int64_t>);
    process_const("INT64_MUL", Cpp::_mul<int64_t>);
    process_const("INT64_DIV", Cpp::_div<int64_t>);
    process_const("INT64_MOD", Cpp::_mod<int64_t>);
    process_const("INT64_NEG", Cpp::_neg<int64_t>);
    process_const("INT64_AND", Cpp::_and<int64_t>);
    process_const("INT64_OR", Cpp::_or<int64_t>);
    process_const("INT64_XOR", Cpp::_xor<int64_t>);
    process_const("INT64_LSH", Cpp::_lsh<int64_t>);
    process_const("INT64_RSH", Cpp::_rsh<int64_t>);
    // UINT64
    process_const("UINT64_ADD", Cpp::_add<uint64_t>);
    process_const("UINT64_SUB", Cpp::_sub<uint64_t>);
    process_const("UINT64_MUL", Cpp::_mul<uint64_t>);
    process_const("UINT64_DIV", Cpp::_div<uint64_t>);
    process_const("UINT64_MOD", Cpp::_mod<uint64_t>);
    process_const("UINT64_NEG", Cpp::_neg<uint64_t>);
    process_const("UINT64_AND", Cpp::_and<uint64_t>);
    process_const("UINT64_OR", Cpp::_or<uint64_t>);
    process_const("UINT64_XOR", Cpp::_xor<uint64_t>);
    process_const("UINT64_LSH", Cpp::_lsh<uint64_t>);
    process_const("UINT64_RSH", Cpp::_rsh<uint64_t>);
    // FLOAT
    process_const("FLOAT_ADD", Cpp::_add<float>);
    process_const("FLOAT_SUB", Cpp::_sub<float>);
    process_const("FLOAT_MUL", Cpp::_mul<float>);
    process_const("FLOAT_DIV", Cpp::_div<float>);
    // DOUBLE
    process_const("DOUBLE_ADD", Cpp::_add<double>);
    process_const("DOUBLE_SUB", Cpp::_sub<double>);
    process_const("DOUBLE_MUL", Cpp::_mul<double>);
    process_const("DOUBLE_DIV", Cpp::_div<double>);
    // LONG DOUBLE
    process_const("LONG_DOUBLE_ADD", Cpp::_add<long double>);
    process_const("LONG_DOUBLE_SUB", Cpp::_sub<long double>);
    process_const("LONG_DOUBLE_MUL", Cpp::_mul<long double>);
    process_const("LONG_DOUBLE_DIV", Cpp::_div<long double>);
    // BOOL
    process_const("BOOL_ADD", Cpp::_add<bool>);
    process_const("BOOL_SUB", Cpp::_sub<bool>);
    process_const("BOOL_MUL", Cpp::_mul<bool>);
    process_const("BOOL_DIV", Cpp::_div<bool>);
    process_const("BOOL_MOD", Cpp::_mod<bool>);
    process_const("BOOL_NEG", Cpp::_neg<bool>);
    process_const("BOOL_AND", Cpp::_and<bool>);
    process_const("BOOL_OR", Cpp::_or<bool>);
    process_const("BOOL_XOR", Cpp::_xor<bool>);
    process_const("BOOL_LSH", Cpp::_lsh<bool>);
    process_const("BOOL_RSH", Cpp::_rsh<bool>);
}

int main() {
    out.open("/home/lionell/dev/labs/archeos/lab_1/settings.txt");
    write_header();
    process();
    write_footer();
    out.close();
    return 0;
}