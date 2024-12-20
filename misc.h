#ifndef MISC_H
#define MISC_H

#include <string>

enum Operations {
    ADD = 1,
    SUB, // 2
    DIV, // 3
    MUL, // 4
    MEA, // 5
    STA, // 6
    EXP, // 7
    ROT, // 8
    MOD, // 9
    LOG, // 10
    PER, // 11
    FLO, // 12
    CIE, // 13
    ABS, // 14
    FAC, // 15
    FIB, // 16
    SIN, // 17
    COS, // 18
    TAN, // 19
    ARCSIN, // 20
    ARCCOS, // 21
    ARCTAN, // 22
    HSIN, // 23
    HCOS, // 24
    HTAN, // 25
    HARCSIN, // 26
    HARCCOS, // 27
    HARCTAN, // 28
    RAN, // 29
    NCR, // 30
    NPR, // 31

    SIG, // 32
};

std::string operation_to_string(enum Operations op);
std::string operation_to_string_EXP_ROT_MOD(enum Operations op);

#endif // MISC_H