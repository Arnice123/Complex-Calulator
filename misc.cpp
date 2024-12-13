#include "misc.h"

std::string operation_to_string(enum Operations op) {
    switch (op) {
        case ADD: return "add";
        case SUB: return "subtract";
        case DIV: return "divide";
        case MUL: return "multiply";
        case EXP: return "exponentiate";
        case ROT: return "root";
        default: return "Unknown operation";
    }
}