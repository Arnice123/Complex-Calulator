#ifndef MISC_H
#define MISC_H

#include <string>

enum Operations {
    ADD = 1,
    SUB,
    DIV,
    MUL,
    EXP,
    ROT
};

std::string operation_to_string(enum Operations op);

#endif // MISC_H