#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include <unordered_map>
#include "misc.h"
#include "operations.h"
//#include "complex_opps.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


int main(){
    long double operation;
    cout << "Enter an operation\n[1]-Add\n[2]-Subtract\n[3]-Division\n[4]-Multiplication\n[5]-Mean\n[6]-Exponentiation\n[7]-Rooting\n[8]-Modulo\n[9]-Log\n[10]-Percentage\n[11]-Floor\n[12]-Ciel\n[13]-Absolute Value\n[14]-Factorial\n[15]-Fibonacci\n[16]-Sine\n[17]-Cosine\n[18]-Tangent\n[19]-Arcsine\n[20]-Arccosine\n[21]-Arctangent\n";
    cout << "\nMore complext operations:\n[22]-Sum of\n";
    cin >> operation;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int range[] = {1, SIG};
    
    while (operation < range[0] || operation > range[1]) {
        cout << "Please enter a valid input: "; 
        cin >> operation;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    enum Operations op = static_cast<Operations>(static_cast<int>(operation));
    long double result;

    if (op < EXP)
    {
        vector<long double> nums;
        string input = "";
        cout << "Input all the numbers you would like to " << operation_to_string(op) <<": ";
        bool minNumbersEntered = false;
        bool emptyInput = false;

        while (true)  
        {
            getline(cin, input);

            minNumbersEntered = (nums.size() >= 2) ? true : false;

            if (input.empty()) 
            {
                emptyInput = true;
                if (!minNumbersEntered) cout << "\nYou need to input at least 2 numbers to run this calculator in this mode." << endl;
            }
            else{
                emptyInput = false;
            }

            if (!emptyInput)
            {
                try {
                    nums.push_back(stold(input));
                }
                catch (const std::invalid_argument& e) {
                    cout << "Invalid input. Please enter a valid number.\n";
                }                
            }

            if (minNumbersEntered && emptyInput) break;
        }

        switch (op)
        {
            case ADD:
                result = add(nums);
                break;
            case SUB:
                result = subtract(nums);
                break;
            case MUL:
                result = multiply(nums);
                break;
            case DIV:
                result = divide(nums);
                break;
            case MEA:
                result = mean(nums);
                break;
        }
    }
    else if (op < FLO){
        long double first;
        long double second;
        cout << "Input the number to be modified: ";
        cin >> first;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Input the " << operation_to_string_EXP_ROT_MOD(op) << ": ";
        cin >> second;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(op)
        {
            case EXP:
                result = pow(first, second);
                break;
            case ROT:
                result = root(first, second, 1e-20);
                break;
            case MOD:
                result = modulo(first, second);
                break;
            case LOG:
                result = log(first, second);
                break;
            case PER:
                result = percentage(first, second);
                break;
        }
    }
    else if (op < SIN){
        long double x;
        cout << "Input the number to be modified: ";
        cin >> x;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::unordered_map<int, long double> val;
        vector<bool>visted(30000, false);
         std::unordered_map<long double, long double> values;

        switch(op)
        {
            case FLO:
                result = m_floor(x);
                break;
            case CIE:
                result = ciel(x);
                break;
            case ABS:
                result = abs(x);
                break;
            case FAC:            
                result = factorial(x, val);
                break;
            case FIB:
                result = fibonacci(x, values, visted);
                break;
        }
    }
    else if (op < SIG)
    {
        long double first;
        long double second;
        cout << "Input the number to be modified: ";
        cin >> first;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Radians-[0] or Degrees-[1]: ";
        cin >> second;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::unordered_map<int, long double> val;

        first = (second) ? ((first < ARCSIN || first > ARCTAN) ? first : first * M_PI / 180 ) : first;
 
        switch(op)
        {
            case SIN:
                result = round_up(sine(first, 100, val), 9);
                break;
            case COS:
                result = round_up(cosine(first, 100, val), 9);
                break;
            case TAN:
                result = round_up(tangent(first, 100, val), 9);
                break;
            case ARCSIN:
                result = arcsine(first, 100, val);
                result = round_up((second) ? result * 180 / M_PI : result, 9);
                break;
            case ARCCOS:
                result = round_up(arccosine(first, 100, val), 9);
                result = (second) ? result * 180 / M_PI : result;
                break;
            case ARCTAN:
                result = round_up(arctangent(first, 100, val), 9);
                result = (second) ? result * 180 / M_PI : result;
                break;
        }
    }
    else if (op == SIG){
        long double i;
        long double n;
        std::string operation;
        std::unordered_map<int, long double> memo;
        cout << "Input I: ";
        cin >> i;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Input N: ";
        cin >> n;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Input the formula: ";
        cin >> operation;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        result = sigmaNotation(operation, i, n, memo);
    }

    cout << "Result of the operation is: " << result << endl;
    return 0;
}