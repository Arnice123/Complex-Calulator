#include "misc.h"

std::string operation_to_string(enum Operations op) {
    switch (op) {
        case ADD: return "add";
        case SUB: return "subtract";
        case DIV: return "divide";
        case MUL: return "multiply";
        case EXP: return "exponentiate";
        case ROT: return "root";
        case MOD: return "modulo";
        case FLO: return "floor";
        case CIE: return "ciel";
        default: return "Unknown operation";
    }
}

std::string operation_to_string_EXP_ROT_MOD(enum Operations op)
{
    switch (op) {
        case EXP: return "power";
        case ROT: return "n-root";
        case MOD: return "divisor";
        default: return "Unknown operation";
    }
}