#ifndef BASIC_OPPS_H
#define BASIC_OPPS_H

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <limits>
#include <functional>
#include <chrono>
#ifndef M_PI
    #define M_PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912  
#endif

#ifndef M_E
    #define M_E 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427427466391932003059921817413596629043572900334295260595630738132328627943490763233829880753195251019011573834187930702154089149934884167509244761460668082264800168477411853742345442437107539077744992069551702761838606261331384583000752044933826560297606737113200709328709127443747047230696977209310141692836819025515108657463772111252389784425056953696770785449969967946864454905987931636889230098793127
#endif

long double add(std::vector<long double> nums);
long double subtract(std::vector<long double> nums);
long double multiply(std::vector<long double> nums);
long double divide(std::vector<long double> nums);
long double mean(std::vector<long double> nums);
long double standard_deviation(std::vector<long double> nums);
long double pow(long double base, long double exp);
long double root(long double x, long double n, long double tolerance);
long double modulo(long double a, long double b);
long double percentage(long double percentage, long double number);
long double abs(long double x);
long double m_floor(long double x);
long double ciel(long double x);
long double factorial(int n, std::unordered_map<int, long double>& memo);
long double fibonacci(long double x, std::unordered_map<long double, long double> &calculatedFib, std::vector<bool> &visted);
long double log(long double x, long double base);
long double sine(long double x, int terms, std::unordered_map<int, long double>& memo);
long double cosine(long double x, int terms, std::unordered_map<int, long double>& memo);
long double tangent(long double x, int terms, std::unordered_map<int, long double>& memo);
long double arcsine(long double x, int terms, std::unordered_map<int, long double>& memo);
long double arccosine(long double x, int terms, std::unordered_map<int, long double>& memo);
long double arctangent(long double x, int terms, std::unordered_map<int, long double>& memo);
long double h_sine(long double x);
long double h_cosine(long double x);
long double h_tangent(long double x);
long double h_arcsine(long double x);
long double h_arccosine(long double x);
long double h_arctangent(long double x);
long double round_up(long double value, int decimal_places);
long double random_num(long double min, long double max);
long double n_choose_r(long double n, long double r, std::unordered_map<int, long double> &memo);
long double n_permutations_r(long double n, long double r, std::unordered_map<int, long double> &memo);

// complex instructions
std::vector<std::string> tokenize(const std::string& instruction);
std::string join(const std::vector<std::string>& tokens, const std::string& delimiter);
std::function<long double(long double)> subFuncBuilder(size_t& i, std::vector<std::string> tokens, std::unordered_map<int, long double> &memo);
std::function<long double(long double)> parseInstruction(const std::string& instruction, std::unordered_map<int, long double> &memo);
long double sigmaNotation(const std::string& instruction, long double i, long double n, std::unordered_map<int, long double> &memo);


#endif