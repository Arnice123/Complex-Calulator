#ifndef BASIC_OPPS_H
#define BASIC_OPPS_H


#include <vector>
#include <stdexcept>

long double add(std::vector<long double> nums);
long double subtract(std::vector<long double> nums);
long double multiply(std::vector<long double> nums);
long double divide(std::vector<long double> nums);
long double exponentiation(long double base, long double exp);
long double root(long double x, long double n, long double tolerance);
long double modulo(long double a, long double b);
long double abs(long double x);
long double m_floor(long double x);
long double ciel(long double x);

#endif