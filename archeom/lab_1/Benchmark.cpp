//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#include "Benchmark.h"
#include "utils/Timer.h"
#include "settings.h"
#include "ops/Cpp.h"
#include "ops/Asm.h"
#include "io/TablePrinter.h"

std::vector<std::tuple<std::string, std::string, double>> Benchmark::run_cpp(std::ostream *out) {
    std::vector<std::tuple<std::string, std::string, double>> data;
    TablePrinter tp("CPP BENCHMARK", out);
    tp.add_column("TYPE", 10);
    tp.add_column("TIME", 15);
    tp.print_header();
    // INT8
    Timer timer;
    data.emplace_back("+", "INT8", Timer::speed_it(Cpp::_add<int8_t>, CPP_INT8_ADD));
    data.emplace_back("-", "INT8", Timer::speed_it(Cpp::_sub<int8_t>, CPP_INT8_SUB));
    data.emplace_back("*", "INT8", Timer::speed_it(Cpp::_mul<int8_t>, CPP_INT8_MUL));
    data.emplace_back("/", "INT8", Timer::speed_it(Cpp::_div<int8_t>, CPP_INT8_DIV));
    data.emplace_back("%", "INT8", Timer::speed_it(Cpp::_mod<int8_t>, CPP_INT8_MOD));
    data.emplace_back("~", "INT8", Timer::speed_it(Cpp::_neg<int8_t>, CPP_INT8_NEG));
    data.emplace_back("&", "INT8", Timer::speed_it(Cpp::_and<int8_t>, CPP_INT8_AND));
    data.emplace_back("|", "INT8", Timer::speed_it(Cpp::_or<int8_t>, CPP_INT8_OR));
    data.emplace_back("^", "INT8", Timer::speed_it(Cpp::_xor<int8_t>, CPP_INT8_XOR));
    data.emplace_back("<<", "INT8", Timer::speed_it(Cpp::_lsh<int8_t>, CPP_INT8_LSH));
    data.emplace_back(">>", "INT8", Timer::speed_it(Cpp::_rsh<int8_t>, CPP_INT8_RSH));
    timer.stop();
    tp << "INT8" << std::to_string(timer.duration()) + "s.";
    // UINT8
    timer.restart();
    data.emplace_back("+", "UINT8", Timer::speed_it(Cpp::_add<uint8_t>, CPP_UINT8_ADD));
    data.emplace_back("-", "UINT8", Timer::speed_it(Cpp::_sub<uint8_t>, CPP_UINT8_SUB));
    data.emplace_back("*", "UINT8", Timer::speed_it(Cpp::_mul<uint8_t>, CPP_UINT8_MUL));
    data.emplace_back("/", "UINT8", Timer::speed_it(Cpp::_div<uint8_t>, CPP_UINT8_DIV));
    data.emplace_back("%", "UINT8", Timer::speed_it(Cpp::_mod<uint8_t>, CPP_UINT8_MOD));
    data.emplace_back("~", "UINT8", Timer::speed_it(Cpp::_neg<uint8_t>, CPP_UINT8_NEG));
    data.emplace_back("&", "UINT8", Timer::speed_it(Cpp::_and<uint8_t>, CPP_UINT8_AND));
    data.emplace_back("|", "UINT8", Timer::speed_it(Cpp::_or<uint8_t>, CPP_UINT8_OR));
    data.emplace_back("^", "UINT8", Timer::speed_it(Cpp::_xor<uint8_t>, CPP_UINT8_XOR));
    data.emplace_back("<<", "UINT8", Timer::speed_it(Cpp::_lsh<uint8_t>, CPP_UINT8_LSH));
    data.emplace_back(">>", "UINT8", Timer::speed_it(Cpp::_rsh<uint8_t>, CPP_UINT8_RSH));
    timer.stop();
    tp << "UINT8" << std::to_string(timer.duration()) + "s.";
    // INT16
    timer.restart();
    data.emplace_back("+", "INT16", Timer::speed_it(Cpp::_add<int16_t>, CPP_INT16_ADD));
    data.emplace_back("-", "INT16", Timer::speed_it(Cpp::_sub<int16_t>, CPP_INT16_SUB));
    data.emplace_back("*", "INT16", Timer::speed_it(Cpp::_mul<int16_t>, CPP_INT16_MUL));
    data.emplace_back("/", "INT16", Timer::speed_it(Cpp::_div<int16_t>, CPP_INT16_DIV));
    data.emplace_back("%", "INT16", Timer::speed_it(Cpp::_mod<int16_t>, CPP_INT16_MOD));
    data.emplace_back("~", "INT16", Timer::speed_it(Cpp::_neg<int16_t>, CPP_INT16_NEG));
    data.emplace_back("&", "INT16", Timer::speed_it(Cpp::_and<int16_t>, CPP_INT16_AND));
    data.emplace_back("|", "INT16", Timer::speed_it(Cpp::_or<int16_t>, CPP_INT16_OR));
    data.emplace_back("^", "INT16", Timer::speed_it(Cpp::_xor<int16_t>, CPP_INT16_XOR));
    data.emplace_back("<<", "INT16", Timer::speed_it(Cpp::_lsh<int16_t>, CPP_INT16_LSH));
    data.emplace_back(">>", "INT16", Timer::speed_it(Cpp::_rsh<int16_t>, CPP_INT16_RSH));
    timer.stop();
    tp << "INT16" << std::to_string(timer.duration()) + "s.";
    // UINT16
    timer.restart();
    data.emplace_back("+", "UINT16", Timer::speed_it(Cpp::_add<uint16_t>, CPP_UINT16_ADD));
    data.emplace_back("-", "UINT16", Timer::speed_it(Cpp::_sub<uint16_t>, CPP_UINT16_SUB));
    data.emplace_back("*", "UINT16", Timer::speed_it(Cpp::_mul<uint16_t>, CPP_UINT16_MUL));
    data.emplace_back("/", "UINT16", Timer::speed_it(Cpp::_div<uint16_t>, CPP_UINT16_DIV));
    data.emplace_back("%", "UINT16", Timer::speed_it(Cpp::_mod<uint16_t>, CPP_UINT16_MOD));
    data.emplace_back("~", "UINT16", Timer::speed_it(Cpp::_neg<uint16_t>, CPP_UINT16_NEG));
    data.emplace_back("&", "UINT16", Timer::speed_it(Cpp::_and<uint16_t>, CPP_UINT16_AND));
    data.emplace_back("|", "UINT16", Timer::speed_it(Cpp::_or<uint16_t>, CPP_UINT16_OR));
    data.emplace_back("^", "UINT16", Timer::speed_it(Cpp::_xor<uint16_t>, CPP_UINT16_XOR));
    data.emplace_back("<<", "UINT16", Timer::speed_it(Cpp::_lsh<uint16_t>, CPP_UINT16_LSH));
    data.emplace_back(">>", "UINT16", Timer::speed_it(Cpp::_rsh<uint16_t>, CPP_UINT16_RSH));
    timer.stop();
    tp << "UINT16" << std::to_string(timer.duration()) + "s.";
    // INT32
    timer.restart();
    data.emplace_back("+", "INT32", Timer::speed_it(Cpp::_add<int32_t>, CPP_INT32_ADD));
    data.emplace_back("-", "INT32", Timer::speed_it(Cpp::_sub<int32_t>, CPP_INT32_SUB));
    data.emplace_back("*", "INT32", Timer::speed_it(Cpp::_mul<int32_t>, CPP_INT32_MUL));
    data.emplace_back("/", "INT32", Timer::speed_it(Cpp::_div<int32_t>, CPP_INT32_DIV));
    data.emplace_back("%", "INT32", Timer::speed_it(Cpp::_mod<int32_t>, CPP_INT32_MOD));
    data.emplace_back("~", "INT32", Timer::speed_it(Cpp::_neg<int32_t>, CPP_INT32_NEG));
    data.emplace_back("&", "INT32", Timer::speed_it(Cpp::_and<int32_t>, CPP_INT32_AND));
    data.emplace_back("|", "INT32", Timer::speed_it(Cpp::_or<int32_t>, CPP_INT32_OR));
    data.emplace_back("^", "INT32", Timer::speed_it(Cpp::_xor<int32_t>, CPP_INT32_XOR));
    data.emplace_back("<<", "INT32", Timer::speed_it(Cpp::_lsh<int32_t>, CPP_INT32_LSH));
    data.emplace_back(">>", "INT32", Timer::speed_it(Cpp::_rsh<int32_t>, CPP_INT32_RSH));
    timer.stop();
    tp << "INT32" << std::to_string(timer.duration()) + "s.";
    // UINT32
    timer.restart();
    data.emplace_back("+", "UINT32", Timer::speed_it(Cpp::_add<uint32_t>, CPP_UINT32_ADD));
    data.emplace_back("-", "UINT32", Timer::speed_it(Cpp::_sub<uint32_t>, CPP_UINT32_SUB));
    data.emplace_back("*", "UINT32", Timer::speed_it(Cpp::_mul<uint32_t>, CPP_UINT32_MUL));
    data.emplace_back("/", "UINT32", Timer::speed_it(Cpp::_div<uint32_t>, CPP_UINT32_DIV));
    data.emplace_back("%", "UINT32", Timer::speed_it(Cpp::_mod<uint32_t>, CPP_UINT32_MOD));
    data.emplace_back("~", "UINT32", Timer::speed_it(Cpp::_neg<uint32_t>, CPP_UINT32_NEG));
    data.emplace_back("&", "UINT32", Timer::speed_it(Cpp::_and<uint32_t>, CPP_UINT32_AND));
    data.emplace_back("|", "UINT32", Timer::speed_it(Cpp::_or<uint32_t>, CPP_UINT32_OR));
    data.emplace_back("^", "UINT32", Timer::speed_it(Cpp::_xor<uint32_t>, CPP_UINT32_XOR));
    data.emplace_back("<<", "UINT32", Timer::speed_it(Cpp::_lsh<uint32_t>, CPP_UINT32_LSH));
    data.emplace_back(">>", "UINT32", Timer::speed_it(Cpp::_rsh<uint32_t>, CPP_UINT32_RSH));
    timer.stop();
    tp << "UINT32" << std::to_string(timer.duration()) + "s.";
    // INT64
    timer.restart();
    data.emplace_back("+", "INT64", Timer::speed_it(Cpp::_add<int64_t>, CPP_INT64_ADD));
    data.emplace_back("-", "INT64", Timer::speed_it(Cpp::_sub<int64_t>, CPP_INT64_SUB));
    data.emplace_back("*", "INT64", Timer::speed_it(Cpp::_mul<int64_t>, CPP_INT64_MUL));
    data.emplace_back("/", "INT64", Timer::speed_it(Cpp::_div<int64_t>, CPP_INT64_DIV));
    data.emplace_back("%", "INT64", Timer::speed_it(Cpp::_mod<int64_t>, CPP_INT64_MOD));
    data.emplace_back("~", "INT64", Timer::speed_it(Cpp::_neg<int64_t>, CPP_INT64_NEG));
    data.emplace_back("&", "INT64", Timer::speed_it(Cpp::_and<int64_t>, CPP_INT64_AND));
    data.emplace_back("|", "INT64", Timer::speed_it(Cpp::_or<int64_t>, CPP_INT64_OR));
    data.emplace_back("^", "INT64", Timer::speed_it(Cpp::_xor<int64_t>, CPP_INT64_XOR));
    data.emplace_back("<<", "INT64", Timer::speed_it(Cpp::_lsh<int64_t>, CPP_INT64_LSH));
    data.emplace_back(">>", "INT64", Timer::speed_it(Cpp::_rsh<int64_t>, CPP_INT64_RSH));
    timer.stop();
    tp << "INT64" << std::to_string(timer.duration()) + "s.";
    // UINT64
    timer.restart();
    data.emplace_back("+", "UINT64", Timer::speed_it(Cpp::_add<uint64_t>, CPP_UINT64_ADD));
    data.emplace_back("-", "UINT64", Timer::speed_it(Cpp::_sub<uint64_t>, CPP_UINT64_SUB));
    data.emplace_back("*", "UINT64", Timer::speed_it(Cpp::_mul<uint64_t>, CPP_UINT64_MUL));
    data.emplace_back("/", "UINT64", Timer::speed_it(Cpp::_div<uint64_t>, CPP_UINT64_DIV));
    data.emplace_back("%", "UINT64", Timer::speed_it(Cpp::_mod<uint64_t>, CPP_UINT64_MOD));
    data.emplace_back("~", "UINT64", Timer::speed_it(Cpp::_neg<uint64_t>, CPP_UINT64_NEG));
    data.emplace_back("&", "UINT64", Timer::speed_it(Cpp::_and<uint64_t>, CPP_UINT64_AND));
    data.emplace_back("|", "UINT64", Timer::speed_it(Cpp::_or<uint64_t>, CPP_UINT64_OR));
    data.emplace_back("^", "UINT64", Timer::speed_it(Cpp::_xor<uint64_t>, CPP_UINT64_XOR));
    data.emplace_back("<<", "UINT64", Timer::speed_it(Cpp::_lsh<uint64_t>, CPP_UINT64_LSH));
    data.emplace_back(">>", "UINT64", Timer::speed_it(Cpp::_rsh<uint64_t>, CPP_UINT64_RSH));
    timer.stop();
    tp << "UINT64" << std::to_string(timer.duration()) + "s.";
    // float
    timer.restart();
    data.emplace_back("+", "FLOAT", Timer::speed_it(Cpp::_add<float>, CPP_FLOAT_ADD));
    data.emplace_back("-", "FLOAT", Timer::speed_it(Cpp::_sub<float>, CPP_FLOAT_SUB));
    data.emplace_back("*", "FLOAT", Timer::speed_it(Cpp::_mul<float>, CPP_FLOAT_MUL));
    data.emplace_back("/", "FLOAT", Timer::speed_it(Cpp::_div<float>, CPP_FLOAT_DIV));
    timer.stop();
    tp << "FLOAT" << std::to_string(timer.duration()) + "s.";
    // double
    timer.restart();
    data.emplace_back("+", "DOUBLE", Timer::speed_it(Cpp::_add<double>, CPP_DOUBLE_ADD));
    data.emplace_back("-", "DOUBLE", Timer::speed_it(Cpp::_sub<double>, CPP_DOUBLE_SUB));
    data.emplace_back("*", "DOUBLE", Timer::speed_it(Cpp::_mul<double>, CPP_DOUBLE_MUL));
    data.emplace_back("/", "DOUBLE", Timer::speed_it(Cpp::_div<double>, CPP_DOUBLE_DIV));
    timer.stop();
    tp << "DOUBLE" << std::to_string(timer.duration()) + "s.";
    // bool
    timer.restart();
    data.emplace_back("+", "BOOL", Timer::speed_it(Cpp::_add<bool>, CPP_BOOL_ADD));
    data.emplace_back("-", "BOOL", Timer::speed_it(Cpp::_sub<bool>, CPP_BOOL_SUB));
    data.emplace_back("*", "BOOL", Timer::speed_it(Cpp::_mul<bool>, CPP_BOOL_MUL));
    data.emplace_back("/", "BOOL", Timer::speed_it(Cpp::_div<bool>, CPP_BOOL_DIV));
    data.emplace_back("%", "BOOL", Timer::speed_it(Cpp::_mod<bool>, CPP_BOOL_MOD));
    data.emplace_back("~", "BOOL", Timer::speed_it(Cpp::_neg<bool>, CPP_BOOL_NEG));
    data.emplace_back("&", "BOOL", Timer::speed_it(Cpp::_and<bool>, CPP_BOOL_AND));
    data.emplace_back("|", "BOOL", Timer::speed_it(Cpp::_or<bool>, CPP_BOOL_OR));
    data.emplace_back("^", "BOOL", Timer::speed_it(Cpp::_xor<bool>, CPP_BOOL_XOR));
    data.emplace_back("<<", "BOOL", Timer::speed_it(Cpp::_lsh<bool>, CPP_BOOL_LSH));
    data.emplace_back(">>", "BOOL", Timer::speed_it(Cpp::_rsh<bool>, CPP_BOOL_RSH));
    timer.stop();
    tp << "BOOL" << std::to_string(timer.duration()) + "s.";
    tp.print_footer();
    return data;
};

std::vector<std::tuple<std::string, std::string, double>> Benchmark::run_asm(std::ostream *out) {
    std::vector<std::tuple<std::string, std::string, double>> data;
    TablePrinter tp("ASM BENCHMARK", out);
    tp.add_column("TYPE", 10);
    tp.add_column("TIME", 15);
    tp.print_header();
    // INT8
    Timer timer;
    data.emplace_back("+", "INT8", Timer::speed_it(Asm::_add_int8, ASM_INT8_ADD));
    data.emplace_back("-", "INT8", Timer::speed_it(Asm::_sub_int8, ASM_INT8_SUB));
    data.emplace_back("*", "INT8", Timer::speed_it(Asm::_mul_int8, ASM_INT8_MUL));
//    data.emplace_back("/%", "INT8", Timer::speed_it(Asm::_div_mod_int8, ASM_INT8_DIV_MOD));
    timer.stop();
    tp << "INT8" << std::to_string(timer.duration()) + "s.";
    // INT16
    timer.restart();
    data.emplace_back("+", "INT16", Timer::speed_it(Asm::_add_int16, ASM_INT16_ADD));
    data.emplace_back("-", "INT16", Timer::speed_it(Asm::_sub_int16, ASM_INT16_SUB));
//    data.emplace_back("*", "INT16", Timer::speed_it(Asm::_mul_int16, ASM_INT16_MUL));
//    data.emplace_back("/%", "INT16", Timer::speed_it(Asm::_div_mod_int16, ASM_INT16_DIV_MOD));
    timer.stop();
    tp << "INT16" << std::to_string(timer.duration()) + "s.";
    // INT32
    timer.restart();
    data.emplace_back("+", "INT32", Timer::speed_it(Asm::_add_int32, ASM_INT32_ADD));
    data.emplace_back("-", "INT32", Timer::speed_it(Asm::_sub_int32, ASM_INT32_SUB));
//    data.emplace_back("*", "int32", Timer::speed_it(Asm::_mul_int32, ASM_INT32_MUL));
//    data.emplace_back("/%", "int32", Timer::speed_it(Asm::_div_mod_int32, ASM_INT32_DIV_MOD));
    timer.stop();
    tp << "INT32" << std::to_string(timer.duration()) + "s.";

    // INT64
    timer.restart();
    data.emplace_back("+", "INT64", Timer::speed_it(Asm::_add_int64, ASM_INT64_ADD));
    data.emplace_back("-", "INT64", Timer::speed_it(Asm::_sub_int64, ASM_INT64_SUB));
//    data.emplace_back("*", "int64", Timer::speed_it(Asm::_mul_int64, ASM_INT64_MUL));
//    data.emplace_back("/%", "int64", Timer::speed_it(Asm::_div_mod_int64, ASM_INT64_DIV_MOD));
    timer.stop();
    tp << "INT64" << std::to_string(timer.duration()) + "s.";
    tp.print_footer();
    return data;
}
