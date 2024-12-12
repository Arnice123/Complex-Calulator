#include <basic_opps.h>

long double add(vector<long double> nums)
{
    long double total = 0;

    for (long double num : nums)
    {
        total += num;
    }

    return total;
}

long double subtract(vector<long double> nums)
{
    long double total = nums.front() * 2;

    for (long double num : nums)
    {
        total -= num;
    }

    return total;
}

long double multiply(vector<long double> nums)
{
    long double total = 1;

    for (long double num : nums)
    {
        total *= num;
    }

    return total;
}

long double divide(vector<long double> nums)
{
    long double total = 1;

    for (long double num : nums)
    {
        total /= num;
    }

    return total;
}

long double exponetiation(long double base, long double exp)
{
    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }
        
    long double ret = 1;
    while (exp > 0) {
        if (static_cast<long long>(exp) & 1) {
            ret *= base;
        }
        exp = static_cast<long long>(exp) >> 1;
        base = base * base;
    }
    return ret;
}

long double root(long double x, long double n, long double tolerance = 1e-12)
{
    if (x < 0 && static_cast<long long>(n) % 2 == 0) return -1;
    if (x == 0) return 0;

    long double approximation = x / 2;
    double diff;

    do {
        long double new_approximation = approximation - (exponetiation(approximation, n) - x) / (n * exponetiation(approximation, n - 1));
        diff = new_approximation - approximation;
        diff = (diff < 0) ? diff : -diff;
        approximation = new_approximation;
    } while (diff > tolerance);

    return approximation;
}
