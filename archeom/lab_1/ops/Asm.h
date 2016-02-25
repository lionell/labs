//
// Created by lionell on 21.02.16.
// Copyright (c) 2016 Ruslan Sakevych. All rights reserved.
//

#ifndef LAB_1_ASM_H
#define LAB_1_ASM_H

#include "Op.h"
#include <stdint.h>
#include <iostream>

class Asm : public Op {
public:
    static void _add_int8(uint64_t n) {
        int8_t i = 1;
        int8_t s = 0;
        asm (
        "xorb %%al, %%al;"
                "xorq %%rcx, %%rcx;"
                "CONDT: cmpq %%rdx, %%rcx;"
                "je DONE;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "addb %%bl, %%al;"
                "incq %%rcx;"
                "jmp CONDT;"
                "DONE:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _sub_int8(uint64_t n) {
        int8_t i = 1;
        int8_t s = 0;
        asm (
        "xorb %%al, %%al;"
                "xorq %%rcx, %%rcx;"
                "CONDT1: cmpq %%rdx, %%rcx;"
                "je DONE1;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "subb %%bl, %%al;"
                "incq %%rcx;"
                "jmp CONDT1;"
                "DONE1:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _mul_int8(uint64_t n) {
        int8_t s;
        asm (
        "movb $0x1, %%al;"
                "xorq %%rcx, %%rcx;"
                "CONDT2: cmpq %%rdx, %%rcx;"
                "je DONE2;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "imulb %%al;"
                "incq %%rcx;"
                "jmp CONDT2;"
                "DONE2:;"
        : "=a" (s)
        : "d" (n)
        );
    }

    static void _div_mod_int8(uint64_t n) {
        int8_t s;
        asm (
        "movb $0x1, %%al;"
                "xorq %%rcx, %%rcx;"
                "CONDT3: cmpq %%rdx, %%rcx;"
                "je DONE3;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "idivb %%al;"
                "incq %%rcx;"
                "jmp CONDT3;"
                "DONE3:;"
        : "=a" (s)
        : "d" (n)
        );
    }

    static void _add_int16(uint64_t n) {
        int16_t i = 1;
        int16_t s = 0;
        asm (
        "xorw %%ax, %%ax;"
                "xorq %%rcx, %%rcx;"
                "CONDT4: cmpq %%rdx, %%rcx;"
                "je DONE4;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "addw %%bx, %%ax;"
                "incq %%rcx;"
                "jmp CONDT4;"
                "DONE4:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _sub_int16(uint64_t n) {
        int16_t i = 1;
        int16_t s = 0;
        asm (
        "xorw %%ax, %%ax;"
                "xorq %%rcx, %%rcx;"
                "CONDT5: cmpq %%rdx, %%rcx;"
                "je DONE5;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "subw %%bx, %%ax;"
                "incq %%rcx;"
                "jmp CONDT5;"
                "DONE5:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _mul_int16(uint64_t n) { // FIX
        int16_t s;
        asm (
        "movw $0x1, %%ax;"
                "xorq %%rcx, %%rcx;"
                "CONDT6: cmpq %%rdx, %%rcx;"
                "je DONE6;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "imul %%ax;"
                "incq %%rcx;"
                "jmp CONDT6;"
                "DONE6:;"
        : "=a" (s)
        : "d" (n)
        );
    }

    static void _div_mod_int16(uint64_t n) {
        int16_t s;
        asm (
        "movw $0x1, %%ax;"
                "xorq %%rcx, %%rcx;"
                "CONDT7: cmpq %%rdx, %%rcx;"
                "je DONE7;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "idivw %%ax;"
                "incq %%rcx;"
                "jmp CONDT7;"
                "DONE7:;"
        : "=a" (s)
        : "d" (n)
        );
    }

    static void _add_int32(uint64_t n) {
        int32_t i = 1;
        int32_t s = 0;
        asm (
        "xorl %%eax, %%eax;"
                "xorq %%rcx, %%rcx;"
                "CONDT8: cmpq %%rdx, %%rcx;"
                "je DONE8;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "addl %%ebx, %%eax;"
                "incq %%rcx;"
                "jmp CONDT8;"
                "DONE8:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _sub_int32(uint64_t n) {
        int32_t i = 1;
        int32_t s = 0;
        asm (
        "xorl %%eax, %%eax;"
                "xorq %%rcx, %%rcx;"
                "CONDT9: cmpq %%rdx, %%rcx;"
                "je DONE9;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "subl %%ebx, %%eax;"
                "incq %%rcx;"
                "jmp CONDT9;"
                "DONE9:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _add_int64(uint64_t n) {
        int64_t i = 1;
        int64_t s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "xorq %%rcx, %%rcx;"
                "CONDT10: cmpq %%rdx, %%rcx;"
                "je DONE10;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "addq %%rbx, %%rax;"
                "incq %%rcx;"
                "jmp CONDT10;"
                "DONE10:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _sub_int64(uint64_t n) {
        int64_t i = 1;
        int64_t s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "xorq %%rcx, %%rcx;"
                "CONDT11: cmpq %%rdx, %%rcx;"
                "je DONE11;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "subq %%rbx, %%rax;"
                "incq %%rcx;"
                "jmp CONDT11;"
                "DONE11:;"
        : "=a" (s)
        : "b" (i), "d" (n)
        );
    }

    static void _add_float(uint64_t n) {
        float i = .5f;
        float s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "movq %2, %%rbx;"
                "fldz;"
                "CONDT12: cmpq %%rbx, %%rax;"
                "je DONE12;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "fld %1;"
                "faddp;"
                "incq %%rax;"
                "jmp CONDT12;"
                "DONE12: fstp %0;"
        : "=m" (s)
        : "m" (i), "m" (n)
        );
    }

    static void _sub_float(uint64_t n) {
        float i = .5f;
        float s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "movq %2, %%rbx;"
                "fldz;"
                "CONDT13: cmpq %%rbx, %%rax;"
                "je DONE13;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "fld %1;"
                "fsubp;"
                "incq %%rax;"
                "jmp CONDT13;"
                "DONE13: fstp %0;"
        : "=m" (s)
        : "m" (i), "m" (n)
        );
    }

    static void _add_double(uint64_t n) {
        double i = .5f;
        double s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "movq %2, %%rbx;"
                "fldz;"
                "CONDT14: cmpq %%rbx, %%rax;"
                "je DONE14;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "fldl %1;"
                "faddp;"
                "incq %%rax;"
                "jmp CONDT14;"
                "DONE14: fstl %0;"
        : "=m" (s)
        : "m" (i), "m" (n)
        );
    }

    static void _sub_double(uint64_t n) {
        float i = .5f;
        float s = 0;
        asm (
        "xorq %%rax, %%rax;"
                "movq %2, %%rbx;"
                "fldz;"
                "CONDT15: cmpq %%rbx, %%rax;"
                "je DONE15;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "fldl %1;"
                "fsubp;"
                "incq %%rax;"
                "jmp CONDT15;"
                "DONE15: fstp %0;"
        : "=m" (s)
        : "m" (i), "m" (n)
        );
    }
};


#endif //LAB_1_ASM_H
