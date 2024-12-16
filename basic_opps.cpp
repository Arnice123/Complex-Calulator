#include "basic_opps.h"

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

long double pow(long double base, long double exp) 
{
    if (base == 0) {
        if (exp <= 0) throw std::domain_error("Undefined: 0 raised to a non-positive power.");
        return 0;
    }
    if (base == 1 || exp == 0) return 1;

    if (exp < 0) {
        base = 1 / base;
        exp = -exp;
    }

    if (m_floor(exp) != exp) {
        return pow(base, static_cast<long double>(m_floor(exp))) * pow(base, exp - m_floor(exp));
    }

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
        long double new_approximation = approximation - (pow(approximation, n) - x) / (n * pow(approximation, n - 1));
        diff = abs(new_approximation - approximation);
        approximation = new_approximation;
    } while (diff > tolerance);

    return approximation;
}

long double modulo(long double a, long double b)
{
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a - b * m_floor(a / b);
}

long double abs(long double x)
{
    return (x < 0) ? -x : x;
}

long double m_floor(long double x) 
{
    long double truncated = static_cast<long long>(x);
    if (x < 0 && x != truncated) {
        return truncated - 1;
    }
    return truncated;
}

long double ciel(long double x) 
{
    long double truncated = static_cast<long long>(x);
    if (x > 0 && x != truncated) {
        return truncated + 1;
    }
    return truncated;
}

long double factorial(int n, std::unordered_map<int, long double>& memo) 
{
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    }

    if (n == 0 || n == 1) return 1.0L;

  int largest_calculated = 1;
    for (const auto& pair : memo) {
        if (pair.first <= n && pair.first > largest_calculated) {
            largest_calculated = pair.first;
        }
    }

    long double result = (largest_calculated > 1) ? memo[largest_calculated] : 1.0L;

    for (int i = (largest_calculated > 1 ? largest_calculated + 1 : 2); i <= n; ++i) {
        result *= i;
        memo[i] = result;
    }

    return result;
}

long double fibonacci(long double x, std::unordered_map<long double, long double> &calculatedFib, std::vector<bool> &visted)
{
    if (x < 0) throw std::invalid_argument("Needs to be positive to do fibonacci");
    if (x == 0.0 || x == 1.0) return x;

    calculatedFib[0] = 0;
    calculatedFib[1] = 1;
    visted[0] = true;
    visted[1] = true;

    for (long double i = 2; i <= x; ++i)
    {
        if (!visted[i])
        {
            calculatedFib[i] = calculatedFib[i-1] + calculatedFib[i-2];
            visted[i] = true;
        }
    }
    return calculatedFib[x];
}

long double log(long double x, long double base = 10.0) 
{
    if (x <= 0) {
        throw std::invalid_argument("Logarithm is undefined for non-positive numbers");
    }
    
    if (x == 1.0) return 0.0;
    
    int integerPart = 0;
    long double current = 1.0;
    
    while (current * base <= x) {
        current *= base;
        integerPart++;
    }
    
    long double fractionalPart = 0.0;
    long double remainder = x / current;
    long double multiplier = 0.5;
    
    for (int i = 0; i < 10; i++) {
        long double testVal = pow(base, fractionalPart + multiplier);
        
        if (testVal <= remainder) {
            fractionalPart += multiplier;
        }
        
        multiplier *= 0.5;
    }
    
    return integerPart + fractionalPart;
}

long double percentage(long double percentage, long double number)
{
    return number * (percentage / 100);
}

long double sine(long double x, int terms, std::unordered_map<int, long double>& memo) 
{
    x = modulo(x, 2 * M_PI);

    long double result = 0.0;

    for (int n = 0; n < terms; ++n) {
        long double term = (n % 2 == 0 ? 1 : -1) * (pow(x, 2 * n + 1) / factorial(2 * n + 1, memo));
        result += term;
    }

    return result;
}

long double cosine(long double x, int terms, std::unordered_map<int, long double>& memo)
{

    x = modulo(x, 2 * M_PI);

    long double result = 0.0;

    for (int n = 0; n < terms; ++n) {
        long double term = (n % 2 == 0 ? 1 : -1) * (pow(x, 2 * n) / factorial(2 * n, memo));
        result += term;
    }
    return result;
}

long double tangent(long double x, int terms, std::unordered_map<int, long double>& memo)
{
     x = modulo(x, M_PI);
    if (x > M_PI/2) x -= M_PI;

    if (abs(x - M_PI/2) < 1e-10 || abs(x + M_PI/2) < 1e-10) {
        return std::numeric_limits<long double>::quiet_NaN();
    }

    long double sinx = sine(x, terms, memo);
    long double cosx = cosine(x, terms, memo);

    if (abs(cosx) < 1e-10) {
        return std::numeric_limits<long double>::quiet_NaN();
    }

    return sinx / cosx;
}

long double round_up(long double value, int decimal_places) 
{
    if (value != value) return value;
    const long double multiplier = pow(10.0, decimal_places);
    return ciel(value * multiplier) / multiplier;
}

long double arcsine(long double x, int terms, std::unordered_map<int, long double>& memo)
{   
    if (x < -1 || x > 1) return std::numeric_limits<long double>::quiet_NaN();

    long double result = x;  // First term
    long double term = x;    // Current term (starts as x)
    
    for (int n = 1; n < terms; ++n) {
        // Recurrence relation: term *= ((2n-1)^2 * x^2) / (2n * (2n+1))
        term *= (2.0 * n - 1) * (2.0 * n - 1) * x * x / (2.0 * n * (2.0 * n + 1));
        result += term;

        // Stop if the term is smaller than a precision threshold
        if (abs(term) < 1e-15) break;
    }
    /*long double result = 0.0;

    for (int n = 0; n < terms; ++n) {
        long double term = (factorial(2 * n, memo) * pow(x, 2 * n + 1))/(pow(4, n) * pow((factorial(n, memo)), 2) * (2 * n + 1));
        result += term;
    }*/

    return result;
}

long double arccosine(long double x, int terms, std::unordered_map<int, long double>& memo)
{
    if (x < -1 || x > 1) return std::numeric_limits<long double>::quiet_NaN();
    return M_PI/2 -arcsine(x, terms, memo);
}

long double arctangent(long double x, int terms, std::unordered_map<int, long double>& memo)
{
    if (x < -1 || x > 1) return std::numeric_limits<long double>::quiet_NaN();
    long double result = 0.0;

    for (int n = 0; n < terms; ++n) {
        long double term = (n % 2 == 0 ? 1 : -1) * (pow(x, 2 * n + 1) / (2 * n + 1));
        result += term;
    }

    return result;
}