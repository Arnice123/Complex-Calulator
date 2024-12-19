#include "operations.h"

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

long double mean(std::vector<long double> nums)
{
    return add(nums)/nums.size();
}

long double standard_deviation(std::vector<long double> nums)
{
    long double _mean = mean(nums);
    size_t size = nums.size();
    for (size_t i = 0; i < size; ++i)
    {
        nums[i] -= _mean;
        nums[i] = pow(nums[i], 2);
    }
    long double new_mean = mean(nums);
    return root(new_mean, 2, 1.0E-200L);
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
    if (x < 0 && modulo(n, 2) == 0) return -1;
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

    if (x > 0.5) {
        return M_PI/2 - arcsine(root((1 - x * x), 2), terms, memo);
    } else if (x < -0.5) {
        return -M_PI/2 - arcsine(root((1 - x * x), 2), terms, memo);
    }

    long double result = x;
    long double term = x;
    
    for (int n = 1; n < terms; ++n) {
        term *= (2.0 * n - 1) * (2.0 * n - 1) * x * x / (2.0 * n * (2.0 * n + 1));
        result += term;

        if (abs(term) < 1e-15) break;
    }

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
    long double term = x;
    for (int n = 0; n < terms; ++n) {
        if (n > 0) term *= -x * x * (2 * n - 1) / (2 * n + 1); 
        result += term;
        if (abs(term) < 1e-15) break;
    }

    return result;
}

long double h_sine(long double x)
{
    // (e^x - e^-x) / (2)
    long double e_x = pow(M_E, x);
    long double e_negative_x = 1 / e_x;
    return (e_x - e_negative_x) / 2;
}

long double h_cosine(long double x)
{
    // (e^x + e^-x) / (2)
    long double e_x = pow(M_E, x);
    long double e_negative_x = 1 / e_x;
    return (e_x + e_negative_x) / 2;
}

long double h_tangent(long double x)
{
    long double e_2x = pow(M_E, 2 * x);
    return (e_2x - 1) / (e_2x + 1);
}

long double h_arcsine(long double x)
{
    // ln(x + sqrt(x^2+1))
    long double x_sqrd = pow(x, 2);
    long double sqrt = root(x_sqrd + 1, 2);
    return log(x + sqrt, M_E);
}

long double h_arccosine(long double x)
{
    // ln(x + sqrt(x^2-1)) x >= 1
    if (x < 1) return std::numeric_limits<long double>::quiet_NaN();
    long double x_sqrd = pow(x, 2);
    long double sqrt = root(x_sqrd - 1, 2);
    return log(x + sqrt, M_E);
}

long double h_arctangent(long double x)
{
    if (x < -1 || x > 1) return std::numeric_limits<long double>::quiet_NaN();
    return (log((x+1)/(x-1), M_E)) / 2
}

long double random_num(long double min, long double max)
{
    auto moment1 = std::chrono::steady_clock::now().time_since_epoch().count();
    auto moment2 = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    auto combined = moment1 ^ moment2;
    long double normalized = modulo(combined, 1000000000LL) / 1000000000.0;
    return min + normalized * (max - min);
}

long double n_choose_r(long double n, long double r, std::unordered_map<int, long double> &memo)
{
    long double n_fact = factorial(n, memo);
    long double r_fact = factorial(r, memo);
    long double n_minus_r = factorial(n - r, memo);
    return n_fact/(r_fact * n_minus_r);
}

long double n_permutations_r(long double n, long double r, std::unordered_map<int, long double> &memo)
{
    long double n_fact = factorial(n, memo);
    long double n_minus_r = factorial(n - r, memo);
    return n_fact/n_minus_r;
}

std::vector<std::string> tokenize(const std::string& instruction)
{
    std::vector<std::string> tokens;
    std::string token;

    for (char ch : instruction)
    {
        if (std::isspace(ch)) continue;

        if (std::isdigit(ch) || ch == '.')
        {
            token += ch; 
        }
        else
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, ch));
        }

        if (!token.empty())
        {
            tokens.push_back(token);
            token.clear();
        }
    }

    return tokens;
}

std::function<long double(long double)> parseInstruction(const std::string& instruction, std::unordered_map<int, long double> &memo)
{
    auto tokens = tokenize(instruction);
    std::function<long double(long double)> func = [](long double ) { return 0; };

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i] == "(")
        {
            size_t prev_i = i;
            auto subFunc = subFuncBuilder(i, tokens, memo);
            auto prevFunc = func;
            if (prev_i == 0)
            {
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) + subFunc(x);
                };
            }
            else{
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) * subFunc(x);
                };
            }
        }
        else if (tokens[i] == "*")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) * subFunc(x);
                };
            }
            else{
                long double multiplier = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, multiplier](long double x)
                {
                    if (multiplier != multiplier) return prevFunc(x) * x;
                    return prevFunc(x) * multiplier;
                };
            }

        }
        else if (tokens[i] == "/")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) / subFunc(x);
                };
            }
            else{
                long double divisor = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, divisor](long double x)
                {
                    if (divisor != divisor) return prevFunc(x) / x;
                    return prevFunc(x) / divisor;
                };
            }
        }
        else if (tokens[i] == "+")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) + subFunc(x);
                };
            }
            else{
                long double adder = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, adder](long double x)
                {
                    if (adder != adder) return prevFunc(x) + x;
                    return prevFunc(x) + adder;
                };
            }
        }
        else if (tokens[i] == "-")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return prevFunc(x) - subFunc(x);
                };
            }
            else{
                long double subtractor = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, subtractor](long double x)
                {
                    if (subtractor != subtractor) return prevFunc(x) - x;
                    return prevFunc(x) - subtractor;
                };
            }
        }
        else if (tokens[i] == "!")
        {
            auto prevFunc = func;
            func = [prevFunc, &memo](long double x)
            {
                return factorial(prevFunc(x), memo);
            };
        }
        else if (tokens[i] == "%")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return modulo(prevFunc(x), subFunc(x));
                };
            }
            else{
                long double divisor = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, divisor](long double x)
                {
                    if (divisor != divisor) return modulo(prevFunc(x), x);
                    return modulo(prevFunc(x), divisor);
                };
            }
        }
        else if (tokens[i] == "^")
        {
            if (tokens[i+1] == "(")
            {
                auto subFunc = subFuncBuilder(i, tokens, memo);
                auto prevFunc = func;
                func = [prevFunc, subFunc](long double x)
                {
                    return pow(prevFunc(x), subFunc(x));
                };
            }
            else{
                long double power = (std::isalpha(tokens[++i][0])) ? std::numeric_limits<long double>::quiet_NaN() : std::stold(tokens[i]);
                auto prevFunc = func;
                func = [prevFunc, power](long double x)
                {
                    if (power != power) return pow(prevFunc(x), x);
                    return pow(prevFunc(x), power);
                };
            }
        }
        else if (std::isdigit(tokens[i][0]) || tokens[i][0] == '.')
        {
            long double constant = std::stold(tokens[i]);
            auto prevFunc = func;
            if (i == 0)
            {
                func = [prevFunc, constant](long double x)
                {
                    return prevFunc(x) + constant;
                };
            }
            else{
                func = [prevFunc, constant](long double x)
                {
                    return prevFunc(x) * constant;
                };
            }
        }
        else if (std::isalpha(tokens[i][0])) {
            auto previousFunc = func;
            func = [previousFunc](long double x) {
                return previousFunc(x) + x;
            };
        }
    }

    return func;
}

std::function<long double(long double)> subFuncBuilder(size_t& i, std::vector<std::string> tokens, std::unordered_map<int, long double> &memo)
{
    int bracketCount = 1;
    size_t j = i + 1;
    while (j < tokens.size() && bracketCount > 0)
    {
        if (tokens[j] == "(") bracketCount++;
        if (tokens[j] == ")") bracketCount--;
        j++;
    }

    if (tokens[j] == "!") ++j;
    std::vector<std::string> subTokens(tokens.begin() + i + 1, tokens.begin() + j - 1);
    std::string subInstruction = join(subTokens, " ");
    
    auto subFunc = parseInstruction(subInstruction, memo);
    i = j - 1;
    return subFunc;
}

std::string join(const std::vector<std::string>& tokens, const std::string& delimiter)
{
    std::string result;
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        result += tokens[i];
        if (i < tokens.size() - 1)
            result += delimiter;
    }
    return result;
}

long double sigmaNotation(const std::string& instruction, long double i, long double n, std::unordered_map<int, long double> &memo)
{
    std::function<long double(long double)> func = parseInstruction(instruction, memo);
    long double total = 0;
    for (; i <= n; ++i)
    {
        total += func(i);
    }
    return total;
}