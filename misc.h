#ifndef MISC_H
#define MISC_H

#include <string>

enum Operations {
    ADD = 1,
    SUB, // 2
    DIV, // 3
    MUL, // 4
    MEA, // 5
    EXP, // 6
    ROT, // 7
    MOD, // 8
    LOG, // 9
    PER, // 10
    FLO, // 11
    CIE, // 12
    ABS, // 13
    FAC, // 14
    FIB, // 15
    SIN, // 16
    COS, // 17
    TAN, // 18
    ARCSIN, // 19
    ARCCOS, // 20
    ARCTAN, // 21

    SIG, // 22
};

std::string operation_to_string(enum Operations op);
std::string operation_to_string_EXP_ROT_MOD(enum Operations op);

#endif // MISC_H