#include "misc.h"

std::string operation_to_string(enum Operations op) {
    switch (op) {
        case ADD: return "add";
        case SUB: return "subtract";
        case DIV: return "divide";
        case MUL: return "multiply";
        case MEA: return "calulate the mean of";
        case STA: return "get the standard deviation of";
        case EXP: return "exponentiate";
        case ROT: return "root";
        case MOD: return "modulo";
        case LOG: return "log";
        case PER: return "percentage";
        case FLO: return "floor";
        case CIE: return "ciel";
        case ABS: return "abs";
        case FAC: return "factorial";
        case FIB: return "fibonacci";
        case SIN: return "sine";
        case COS: return "cosine";
        case TAN: return "tangent";
        case ARCSIN: return "arcsine";
        case ARCCOS: return "arccosine";
        case ARCTAN: return "arctangent";
        case RAN: return "random";
        case NCR: return "n choose r";
        case NPR: return "n permutations of r";
        case SIG: return "sum of";
        default: return "Unknown operation";
    }
}

std::string operation_to_string_EXP_ROT_MOD(enum Operations op)
{
    switch (op) {
        case EXP: return "power";
        case ROT: return "n-root";
        case MOD: return "divisor";
        case LOG: return "base";
        case PER: return "number";
        default: return "Unknown operation";
    }
}