#include "basic_opps.h"
#include <cmath>

long double add(std::vector<long double> nums)
{
    long double total = 0;

    for (long double num : nums)
    {
        total += num;
    }

    return total;
}

long double subtract(std::vector<long double> nums)
{
    long double total = nums.front() * 2;

    for (long double num : nums)
    {
        total -= num;
    }

    return total;
}

long double multiply(std::vector<long double> nums)
{
    long double total = 1;

    for (long double num : nums)
    {
        total *= num;
    }

    return total;
}

long double divide(std::vector<long double> nums)
{
    long double total = nums.front() * nums.front();

    for (long double num : nums)
    {
        if (num == 0) throw::std::invalid_argument("Divide by zero error");
        total /= num;
    }

    return total;
}

long double exponentiation(long double base, long double exp) {
    if (base == 0) {
        if (exp <= 0) throw std::domain_error("Undefined: 0 raised to a non-positive power.");
        return 0;
    }
    if (base == 1 || exp == 0) return 1;

    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }

    if (std::floor(exp) != exp) {
        // Handle non-integer exponents
        return std::exp(std::log(base) * exp);
    }

    // Handle integer exponents using binary exponentiation
    long long int_exp = static_cast<long long>(exp);
    long double result = 1;
    while (int_exp > 0) {
        if (int_exp & 1) {
            result *= base;
        }
        base *= base;
        int_exp >>= 1;
    }
    return result;
}

long double root(long double x, long double n, long double tolerance = 1e-200)
{
    if (x < 0 && static_cast<long long>(n) % 2 == 0) return -1;
    if (x == 0) return 0;

    long double approximation = x / 2;
    long double diff;

    do {
        long double new_approximation = approximation - (std::pow(approximation, n) - x) / (n * std::pow(approximation, n - 1));
        diff = std::abs(new_approximation - approximation);
        approximation = new_approximation;
    } while (diff > tolerance);

    return approximation;
}
