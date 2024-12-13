#ifndef MISC_H
#define MISC_H

#include <string>

enum Operations {
    ADD = 1,
    SUB, // 2
    DIV, // 3
    MUL, // 4
    EXP, // 5
    ROT, // 6
    MOD, // 7
    LOG, // 8
    FLO, // 9
    CIE, // 10
    ABS, // 11
    FAC, // 13
    FIB  // 14
};

std::string operation_to_string(enum Operations op);
std::string operation_to_string_EXP_ROT_MOD(enum Operations op);

#endif // MISC_H